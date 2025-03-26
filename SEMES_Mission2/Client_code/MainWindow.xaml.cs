using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Net.Http;

namespace CarAssemblerGUI;

/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
/// 

public partial class MainWindow : Window
{
    static NetworkStream _networkStream;
    // 네트워크 서비스 객체 생성
    NetworkService networkService = new NetworkService(_networkStream);
    List<string> carTypeList = new() { "Select", "SEDAN", "SUV", "TRUCK" };
    List<string> engineTypeList = new() { "Select", "GM", "TOYOTA", "WIA" };
    List<string> breakTypeList = new() { "Select", "MANDO", "CONTINENTAL", "BOSCH" };
    List<string> steeringTypeList = new() { "Select", "BOSCH", "MOBIS" };
    List<ComboBox> SelectList = new();

    public MainWindow()
    {
        InitializeComponent();
        LoadComboBoxItems();
    }

    // 각 List 에 데이터 세팅
    private void LoadComboBoxItems()
    {
        SelectList.Add(selectCartype);
        selectCartype.ItemsSource = carTypeList;
        selectCartype.SelectedIndex = 0;

        SelectList.Add(selectEnginetype);
        selectEnginetype.ItemsSource = engineTypeList;
        selectEnginetype.SelectedIndex = 0;

        SelectList.Add(selectBreaktype); 
        selectBreaktype.ItemsSource = breakTypeList;
        selectBreaktype.SelectedIndex = 0;

        SelectList.Add(selectSteeringtype);  
        selectSteeringtype.ItemsSource = steeringTypeList;
        selectSteeringtype.SelectedIndex = 0;
    }

    // 클릭 시 선택 초기화
    private void Reset_Button(object sender, RoutedEventArgs e)
    {
        for(int i = 0; i < SelectList.Count(); i++)
        {
            SelectList[i].SelectedIndex = 0;
        }
    }

    // 클릭 시 C++로 데이터 전송
    private async void Check_Button(object sender, RoutedEventArgs e)
    {
        string selectedMessage = "";

        for (int i = 0; i < SelectList.Count(); i++)
        {
            if (SelectList[i].SelectedIndex == 0)
            {
                MessageBox.Show(i + 1 + "번째 선택 박스를 선택해주세요.");
                return;
            }
            selectedMessage += SelectList[i].SelectedIndex;
            selectedMessage += ':';
        }

        MessageBox.Show(selectedMessage);

        if (!string.IsNullOrEmpty(selectedMessage))
        {

            // 서버로 메시지 전송 후 응답 받기
            string response = await networkService.SendMessageAndGetResponseAsync(selectedMessage);

            // 응답 처리
            MessageBox.Show($"Server response: {response}", "Response");
        }
        else
        {
            MessageBox.Show("Please select a message from the dropdown.", "Error");
        }
    }
    //private async void Check_Button(object sender, RoutedEventArgs e)
    //{
    //    string selectedMessage = "";

    //    for(int i = 0; i < SelectList.Count(); i++)
    //    {
    //        if (SelectList[i].SelectedIndex == 0)
    //        {
    //            MessageBox.Show(i + 1 + "번째 선택 박스를 선택해주세요.");
    //            return;
    //        }
    //        selectedMessage += SelectList[i].SelectedIndex;
    //        selectedMessage += ':';
    //    }

    //    MessageBox.Show(selectedMessage);

    //    if (!string.IsNullOrEmpty(selectedMessage))
    //    {
    //        byte[] data = Encoding.ASCII.GetBytes(selectedMessage);
    //        await _networkStream.WriteAsync(data, 0, data.Length);

    //        // Receive response from the server
    //        byte[] buffer = new byte[1024];
    //        int bytesRead = await _networkStream.ReadAsync(buffer, 0, buffer.Length);
    //        string response = Encoding.ASCII.GetString(buffer, 0, bytesRead);

    //        MessageBox.Show($"Server response: {response}", "Response");
    //    }
    //    else
    //    {
    //        MessageBox.Show("Please select a message from the dropdown.", "Error");
    //    }
    //}

    private async void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
    {
        // 종료 직전에 서버로 종료 메시지를 보내는 코드
        await networkService.SendExitMessageToServer();

        // 네트워크 스트림 및 연결 종료
        _networkStream?.Close();
    }
}

public class NetworkService
{
    private NetworkStream _networkStream;
    private TcpClient _tcpClient;

    public NetworkService(NetworkStream networkStream)
    {
        _networkStream = networkStream;
        ConnectServer();
    }

    private async void ConnectServer()
    {
        string serverIp = "127.0.0.1";
        //string serverIp = "210.181.151.28";
        int serverPort = 54000; // 서버 포트

        _tcpClient = new TcpClient();
        await _tcpClient.ConnectAsync(serverIp, serverPort);

        _networkStream = _tcpClient.GetStream();
    }

    public async Task<string> SendMessageAndGetResponseAsync(string message)
    {
        try
        {
            if(_networkStream == null)
            {
                return $"An error occurred: Error";
            }
            byte[] data = Encoding.ASCII.GetBytes(message);
            await _networkStream.WriteAsync(data, 0, data.Length);

            // 서버로부터 응답 받기
            byte[] buffer = new byte[1024];
            int bytesRead = await _networkStream.ReadAsync(buffer, 0, buffer.Length);
            string response = Encoding.ASCII.GetString(buffer, 0, bytesRead);
            return response;
        }
        catch (Exception ex)
        {
            return $"An error occurred: {ex.Message}";
        }
    }

    public async Task SendExitMessageToServer()
    {
        if (_networkStream == null)
        {
            MessageBox.Show("NetworkStream is not initialized.");
            return;
        }

        try
        {
            // 종료 메시지 생성
            string exitMessage = "-1";
            byte[] data = Encoding.ASCII.GetBytes(exitMessage);

            // 서버로 종료 메시지 전송
            await _networkStream.WriteAsync(data, 0, data.Length);

            //// 서버로부터 응답 받기
            //byte[] buffer = new byte[1024];
            //int bytesRead = await _networkStream.ReadAsync(buffer, 0, buffer.Length);
            //string response = Encoding.ASCII.GetString(buffer, 0, bytesRead);

            //MessageBox.Show($"Server response: {response}", "Response");
        }
        catch (Exception ex)
        {
            MessageBox.Show($"Error while sending exit message: {ex.Message}", "Error");
        }
    }
}