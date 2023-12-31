//	생성자

	//	명시적으로 정의된 생성자가 한 개라도 존재하면 디폴트 생성자는 호출 될 수 없다.

	//	디폴트 생성자의 호출 조건은 즉슨 명시적으로 정의된 생성자가 단 한개도 없어야 한다.

	//	explicit : 키워드		생성자의 묵시적인 형변환을 방지하여 프로그래머의 의도에 의해서만 생성 할 수 있도록 하는 키워드

		//	CObj	temp = 200 <== 디폴트 대입연산자에 의해 의도하지 않게 200이 대입되는 현상이 일어남 이럴때 사용하는 키워드가 explicit

	//	동적할당이나 객체의 선언등을 통해 객체 배열을 생성시 배열의 길이만큼 생성자 소멸자가 호출된다. (각각의 배열요소인 객체가 생성자 호출을한다..)



	//	생성자내부에서 값을 초기화 하려는 용도로 별도의 멤버 함수를 호출하는것은 옳지 않다. 
	//	생성자의 호출 종료이후 객체생성이 끝나는것인데 생성중인 단계에서 멤버변수를 호출하므로 문제가 생기는것이다.


	

//	전방 선언

	//	두 클래스가 서로를 상호 간 포함 또는 참조하기 때문에 발생하는 현상이다.

		//	두 클래스 중 한 클래스의 헤더파일에 전방 선언을 한다.
		//	전방 선언을 할 경우 멤버 변수로는 포인터 타입으로 객체를 사용해야 한다.
		//	반드시 cpp에 헤더 파일을 포함하여 코드를 사용 할 수 있또록 해야 함
		// 
		//	전방선언은 상호참조를 피하기위한 하나의 해결책이 되어주는것이지 모든 경우에 전방선언을 하는것은 좋은 코딩습관이아니다.
		//	기본적으로 헤더파일의 include는 헤더파일 내에서 이루어지는것이 옳다.	

	//	자료형의 이름을 알려줄뿐이다.

	//	CPP(소스파일에서는) 전방선언을 통해 알 수 없다.. (멤버함수) = > 소스파일에서 별도로 해당 헤더파일을 포함시켜준다.

	//	헤더파일을 불러오는거는 해당클래스의 내부내용을 전부 알 수 있다.


//	정의문 바로 헤더파일에서 그부분만 보이게하는거 물어보기