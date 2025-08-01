* MST 구현 방법 ==> 크루스칼 알고리즘의 개념



* 최소 신장 트리의 특징

&nbsp;  - 사이클이 포함되면 가중치의 합이 최소가 될 수 없으므로 사이클을 포함하지 않는다.

&nbsp;	--> N개의 노드가 있으면 최소 신장 트리를 구성하는 간선의 개수는 항상 N-1개다.

&nbsp;	![Image](https://github.com/user-attachments/assets/add8b7a4-8a77-4f94-9ecf-f89837c13dc1)

* 최소 신장 트리의 핵심 이론

&nbsp;   1. 링크드 리스트로 그래프를 구현 + 유니온 파인드 리스트(사이클 판별을 위해서 사용.) 초기화 하기. 

&nbsp;	- 데이터를 노드가 아닌 간선 중심으로 저장함

&nbsp;    ![Image](https://github.com/user-attachments/assets/0fa60897-a8ed-43a0-830c-f07d5f429ee2)

&nbsp;   2. 그래프 데이터를 가중치 기준으로 정렬하기

&nbsp;      - 에지 리스트에 담긴 그래프 데이터를 \*\*가중치 기준으로 오름차순\*\* 정렬.

&nbsp;   3. 가중치가 낮은 에지부터 연결 시도

&nbsp;	<img width="890" height="416" alt="Image" src="https://github.com/user-attachments/assets/9214e694-fb54-4a5e-bdca-af9f7bc3820f" />

&nbsp;      —>find 연산을 이용해 확인후 사이클이 형성되지 않을 때만 union 연산을 이용해 두 노드를 연결.

&nbsp;            - ex) find(4), find(5) 연산이 다르게 나올때만 연결. 같다면 사이클이 만들어진다는 의미.

&nbsp;            - 사이클이 생긴다는 것은 이미 현재 엣지보다 가중치가 낮은 다른 엣지들로 연결이 되어있다는 의미

&nbsp;    4. 과정 3 반복하기.

&nbsp;	전체 노드의 개수가 n개 이면 연결한 에지의 개수가 n-1이 될 때까지 과정 3을 반복

&nbsp;	![Image](https://github.com/user-attachments/assets/e84c4505-ac17-4079-a3be-809aa621c523)

&nbsp;    5. 총 에지 비용 출력 

