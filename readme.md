문제점

1. 해당 map 유효성 탐색중에 아래의 지도와 같이 아래가 뚫려있는 경우 확인이 안됨
예시)
111111111
100000001
100001101
111111

2. 색 가져올 때 isdigital 함수가 정상적으로 작동하지 않음

3. 2차원 문자배열에 마지막 값인 null에 접근하면 segfault가 뜬다.

------------------------------------------------------

## 08.18

Makefile 수정함: mlx/Makefile도 fclean 추가하기

free_all() 함수 만들 것

------------------------------------------------------

## 08.19

img.ceil && img.floor 안쓰임 > 삭제

map.c line 27: ft_strchr(check[i], '1') error<br />
: 저 부분 때문에 F, C 중에 뒤에 나오는 정보에 1 들어가면 그 부분부터 맵으로 인식함<br />
: F, C를 찾을 수 없을 때부터 맵으로 인식하도록 고쳤으나 너무 주먹구구식이라 마음에 안 듦<br />
: 텍스쳐에도 1이 들어갈 수 있기 때문에 이 부분도 적용시켜야 함<br />

---

## 08.20.

Error 출력 시 Error\n 먼저 출력해야함

---

texture buf에 씌우고 출력하기

---

move: dir_*, plane_* 확인
plane도 방향에 따라 다 다르게 설정해야함

---

raycast.c 31 에러(dda)