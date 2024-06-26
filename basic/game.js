let games = {
    Kong: {period: "197001198104",isServiceEnd: 1, genre: "Adventure", rating: 4.1, max_p:1},
    Ace: {period:"198707202407", isServiceEnd: 0, genre: "Board", rating: 3.8, max_p:4},
    Mario: {period:"200109200711" ,isServiceEnd: 1, genre: "RPG", rating: 3.3, max_p:2},
    Prince: { period: "198303200205", isServiceEnd: 1, genre: "RPG", rating: 4.8, max_p: 1 },
    Dragons: { period: "199005199512", isServiceEnd: 1, genre: "Fight", rating: 3.4, max_p: 4 },
    Civil: { period: "200206202407", isServiceEnd: 0, genre: "Simulation", rating: 4.2, max_p: 1 },
    Teken: { period: "199807200912", isServiceEnd: 1, genre: "Fight", rating: 4.0, max_p: 2 },
    GoCart: { period: "200612202407", isServiceEnd: 0, genre: "Sports", rating: 4.6, max_p: 8 },
    Football: { period: "199406202407", isServiceEnd: 0, genre: "Sports", rating: 2.9, max_p: 8 },
    Brave: { period: "198006198501", isServiceEnd: 1, genre: "RPG", rating: 4.2, max_p: 1 },

};

//param0 특정 시기, param1: 참가 인원수
function find(param0, param1) {
    let date = parseInt(param0, 10);
    let gameNames = Object.keys(games);
    let possible_game = [];
    for (let i = 0; i < gameNames.length; i++){
        let name = gameNames[i];
        let isServiceEnd = games[name].isServiceEnd;
        let dot = isServiceEnd ?'*': "";
        let period = games[name].period;
        let start = parseInt(period.substring(0, 6),10);
        let end = parseInt(period.substring(6, 12),10);
        let genre = games[name].genre;
        let rating = games[name].rating;
        let max_p = games[name].max_p;
        if (date >= start && date <= end && param1 <= max_p) {
            possible_game.push(name+dot+'('+genre+') '+rating);
        }
    }
    possible_game.sort((a, b) => {
        let ratingA = parseFloat(a.match(/[\d.]+$/)[0]);
        let ratingB = parseFloat(b.match(/[\d.]+$/)[0]);
        return ratingB - ratingA;
    });
    return possible_game;
}

let result1 = find("200201", 1); //['Prince*(RPG) 4.8', 'Teken*(Fight) 4', 'Ace(Board) 3.8', 'Mario*(RPG) 3.3', 'Football(Sports) 2.9']
let result2 = find("200201", 4); // ['Ace(Board) 3.8', 'Football(Sports) 2.9']
let result3 = find("198402", 1); // ['Prince*(RPG) 4.8', 'Brave*(RPG) 4.2']
let result4 = find("200008", 8); // ['Football(Sports) 2.9']
let result5 = find("199004", 5); // []
console.log(result1);