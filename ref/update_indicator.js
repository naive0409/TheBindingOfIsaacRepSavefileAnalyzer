function update_indicator(elem) {
    var savedatas = localStorage.getItem(
      "isaac_game_persistentgamedata"
    );
    savedatas = savedatas && parse_savefile_infos(savedatas);
    if (savedatas) {
      indicator.innerHTML = "存档已加载";
      var obj = elem.querySelector(
        "#persistentgamedata_selector_checksum"
      );
      if (obj) {
        obj.innerHTML = savedatas.checksum.toString(16);
      }
      obj = elem.querySelector(
        "#persistentgamedata_selector_death_count"
      );
      if (obj) {
        obj.innerHTML = savedatas.counter.death;
      }
      obj = elem.querySelector(
        "#persistentgamedata_selector_collectibles_count"
      );
      if (obj) {
        var count = 0;
        for (var i = 1; i < savedatas.collectibles.length; i++) {
          if (savedatas.collectibles[i]) {
            count++;
          }
        }
        obj.innerHTML = count;
      }
      obj = elem.querySelector(
        "#persistentgamedata_selector_achievements_count"
      );
      if (obj) {
        var count = 0;
        for (var i = 1; i < savedatas.achis.length; i++) {
          if (savedatas.achis[i]) {
            count++;
          }
        }
        obj.innerHTML = count;
      }
      obj = elem.querySelector(
        "#persistentgamedata_selector_momkills_count"
      );
      if (obj) {
        obj.innerHTML = savedatas.counter.momkills;
      }
      obj = elem.querySelector(
        "#persistentgamedata_selector_beststreak_count"
      );
      if (obj) {
        obj.innerHTML = savedatas.counter.beststreak;
      }
    } else {
      indicator.innerHTML = "存档未加载";
      var obj = elem.querySelector(
        "#persistentgamedata_selector_checksum"
      );
      if (obj) {
        obj.innerHTML = "";
      }
      obj = elem.querySelector(
        "#persistentgamedata_selector_death_count"
      );
      if (obj) {
        obj.innerHTML = "";
      }
      obj = elem.querySelector(
        "#persistentgamedata_selector_collectibles_count"
      );
      if (obj) {
        obj.innerHTML = "";
      }
      obj = elem.querySelector(
        "#persistentgamedata_selector_achievements_count"
      );
      if (obj) {
        obj.innerHTML = "";
      }
      obj = elem.querySelector(
        "#persistentgamedata_selector_momkills_count"
      );
      if (obj) {
        obj.innerHTML = "";
      }
      obj = elem.querySelector(
        "#persistentgamedata_selector_beststreak_count"
      );
      if (obj) {
        obj.innerHTML = "";
      }
    }
  }
