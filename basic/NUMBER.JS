function solution(telno) {
    // -없애는 방법
    let tel = telno.replace(/-/g, '');
    const failure = ["전국", "X"];
    const map = {
        "010": "휴대폰",
        "011": "휴대폰", "016": "휴대폰", "017": "휴대폰", "018": "휴대폰", "019": "휴대폰",
        "031": "경기", "032": "인천", "033": "강원",
        "041": "충청", "042": "대전", "044": "세종",
        "051": "부산", "052": "울산", "053": "대구",
        "054": "경북", "055": "경남",
        "061": "전남", "062": "광주", "063": "전북",
        "064": "제주"
    };
    let top_num_3 = tel.substring(0, 3);
    if((top_num_3==="001"||top_num_3==="002")&&(tel.length>=11&&tel.length<=15)) tel = tel.substring(3);
    else if (tel.length > 11 || tel.length < 9) return failure;
    else if (tel[0] !== '0') return failure;
    top_num_3 = tel.substring(0, 3);
    const last_num_4 = tel.substring(tel.length - 4);

    if (tel[1] === '2') {
        if (tel.length !== 10) return ["서울", "X"];
        if (last_num_4[0] === last_num_4[1] && last_num_4[1] === last_num_4[2] && last_num_4[2] === last_num_4[3]) return ["서울", "X"];
        return ["서울", "O"];
    }
    else if (tel[1] === '1') {
        if (!map[top_num_3]) return failure;
        if (tel[2] !== '0') return ["휴대폰", "X"];
        if (tel.length === 11 && parseInt(tel[3]) % 2 === 0) return ["휴대폰", "O"];
        return ["휴대폰", "X"];
    }
    else if (map[top_num_3]) {
        if (tel.length === 10 && tel[3] === '0') return [map[top_num_3], "X"];
        return [map[top_num_3], "O"];
    }

    return failure;
}

console.log(solution("010-123-1234"));
console.log(solution("010-2234-1234"));
console.log(solution("02-1234-1234"));
console.log(solution("0212341111"));
console.log(solution("0311237890"));
console.log(solution("061-012-7890"));
console.log(solution("015-0157899"));
console.log(solution("042-2123-7890"));
console.log(solution("001-010-123-1234"));
console.log(solution("002-010-2234-1234"));
console.log(solution("001-010-12335-1234"));
console.log(solution("001-042-2123-7890"));