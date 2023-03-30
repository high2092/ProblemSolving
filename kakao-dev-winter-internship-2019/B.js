function 집합_정렬(s, idx) { // {1, 3, 2}, {2}, ...

    const sorted = [];
    while (idx < s.length) {
        if (s[idx] === '{') {
            idx++;

            let resultString = '';

            while (s[idx] !== '}') {
                resultString += s[idx]
                idx++;
            }

            const result = resultString.split(',').map(Number);
            sorted[result.length] = result;

            idx++;
        }

        idx++;
    }


    return sorted;
}

function solution(s) {
    var answer = [];

    const sortedSets = 집합_정렬(s, 1);

    for (let i = 1; i < sortedSets.length; i++) {
        for (const el of sortedSets[i]) {
            if (answer.includes(el)) continue;
            answer.push(el);
        }
    }

    return answer;
}
