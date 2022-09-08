function PlayerMain() {
    let nums = readline();
    let list = nums.split(",");
    parseInt(list);


    //Para debug
    console.error("My Debug Message");
    console.log(resolver(list));

    function resolver(list) {
        let mdcResult = list[0]
        for (let i = 1; i < list.length; i++) {
            mdcResult = mdc(mdcResult, list[i])
        }

        return mdcResult
    }

    function mdc(a, b) {
        while (b !== 0) {
            var r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
}

PlayerMain();