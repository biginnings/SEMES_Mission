<img src="https://capsule-render.vercel.app/api?type=waving&color=BDBDC8&height=150&section=header" width="100%" >


<div align="center">


# 프로젝트에 대한 정보
***

  ### 1. 프로젝트 제목

  “CarAssembler”

  ### 2. 프로젝트 정보 🗂

  명세서의 제조 순서에 따라 자동차를 제작한다.

  `개발기간: 25.07.25 ~ 25.07.27 (3일)`

  ### 3. 데이터 흐름

  CarAssember를 인스턴스화 하여 단일 패턴을 구현함.
  
  Car와 각 부품들을 객체화하여 재사용성을 높임.
  
  순차적으로 입력을 받고 정해진 입력 외엔 에러 처리를 진행함.
  
  GUI로 진행 시 TCP 통신을 통해 GUI로 입력받은 값을 쉘로 전송, 처리하고 결과값을 받아와 Message 창으로 띄움.
  
  시간 관계상 GUI에서 결과들을 List 에 저장해두고 해당 index로 출력하는 방법으로 구현했으나 추후 Json 데이터로 저장하고 쉘, GUI에서 Json에 접근하여 데이터 처리하는 방식으로 수정 가능함.

  ### 4. 실행 방법 🌐
  
  Mission1 : SEMES_Mission1/CarAssemblerMission1/CarAssembler.sln 실행 -> main.cpp 실행
  
  Mission2 : SEMES_Mission2/Clien_code_final/CarAssemberlGUI.sln 실행

</div>


## 기술 스택 📖
<div align="center">

  ![Visual Studio 2022](https://img.shields.io/badge/VisualStudio-5C2D91?style=flat-square&logo=VisualStudio&logoColor=white)
  ![C#](https://img.shields.io/badge/-C%23-000000?logo=Csharp&style=flat)
  ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

</div>

## 팀 소개 👨‍👨‍👦 
  
<div align="center">

<table>
  <tbody>
    <tr>
      <td align="center">
        <sub><b>박찬호</b></sub>
      </td>
      <td align="center">
        <sub><b>전혜림</b></sub>
      </td>
      <td align="center">
        <sub><b>이종하</b></sub>
      </td>
    </tr>
    <tr>
      <td>
        <ul>
          <li><strong>SEMES SW설계</strong></li>
          <li>요구사항 분석 및 SW 설계</li>
          <li>Car 객체 구현 및 리팩토링</li>
        </ul>
      </td>
      <td>
        <ul>
          <li><strong>SEMES SW설계</strong></li>
          <li>C++ - C# 간 TCP 구현</li>
          <li>부품 객체 구현</li>
        </ul>
      </td>
      <td>
        <ul>
          <li><strong>SEMES SW설계</strong></li>
          <li>GUI 제작</li>
          <li>UI/UX 설계 및 리팩토링</li>
        </ul>
      </td>
    </tr>
  </tbody>
</table>

</div>
