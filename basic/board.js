let board = Array(16).fill('x'); // 16칸 보드판 초기화
board[0] = 'S'; // 시작 지점 설정

let players = {
  A: { position: 0, landCount: 0 },
  B: { position: 0, landCount: 0 },
  C: { position: 0, landCount: 0 },
  D: { position: 0, landCount: 0 },
};

function rollDice() {
  return Math.floor(Math.random() * 4) + 1; // 1에서 4 사이의 랜덤한 값 반환
}

function play(moves) {
  let playerNames = Object.keys(players);
  
  for (let i = 0; i < playerNames.length; i++) {
    let player = playerNames[i];
    let steps = moves[i];
    let currentPosition = players[player].position;
    let newPosition = (currentPosition + steps) % 16;

    // 이동 후의 칸을 확인
    if (newPosition !== 0 && board[newPosition] === 'x') {
      board[newPosition] = player; // 빈 칸이면 플레이어의 이니셜로 변경
      players[player].landCount++; // 소유한 땅의 갯수 증가
    }

    players[player].position = newPosition; // 플레이어의 위치 업데이트

    }

  return calculateLand(); // 플레이어들의 소유 땅의 갯수를 반환
}
function calculateLand() {
    let landCountMap = new Map();
    for (let player in players) {
        landCountMap.set(player, players[player].landCount);
    }
    return landCountMap;
}


// 게임 진행
while (board.includes('x')) {
    let moves = [rollDice(), rollDice(), rollDice(), rollDice()];
    let result = play(moves);

    if (!board.includes('x')) {
        let formattedResult = '';
        let first = true;
        for (let [key, value] of result.entries()) {
            if (!first) {
                formattedResult += ', ';
            }
            formattedResult += `${key}: ${value}`;
            first = false;
        }
        console.log(formattedResult);
            break;
    }
}

