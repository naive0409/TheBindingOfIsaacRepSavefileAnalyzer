# function update_indicator(elem)

> 这段代码是一个 JavaScript 函数，用于更新页面上的指示器元素 (`elem`)，以反映游戏存档数据的状态和信息。让我逐步解释这段代码的主要部分：
>
> 1. 首先，代码从本地存储 (`localStorage`) 中获取名为 "isaac_game_persistentgamedata" 的数据，并将其存储在变量 `savedatas` 中。
>
> 2. 然后，代码使用 `parse_savefile_infos` 函数解析 `savedatas` 中的存档数据。如果 `savedatas` 不为 `null` 或 `undefined`，则解析成功，否则解析失败。
>
> 3. 如果存档数据成功解析（`savedatas` 存在），则代码更新页面上的指示器元素，显示 "存档已加载"，并将不同存档信息填充到相应的 HTML 元素中。以下是它的具体操作：
>    - 更新 `indicator` 元素的内容以显示 "存档已加载"。
>    - 获取页面上具有特定 `id` 属性的元素，并更新它们的内容以反映存档数据的不同信息，例如校验和、死亡次数、收藏品数量、成就数量、击败 Mom 的次数以及最佳连胜次数。
>
> 4. 如果存档数据解析失败（`savedatas` 为 `null` 或 `undefined`），则代码更新页面上的指示器元素，显示 "存档未加载"，并将相应的 HTML 元素内容清空。
>
> 总之，这段代码用于根据存档数据的状态来更新页面上的指示器元素，以便玩家能够了解存档的状态和各种游戏数据。这些信息包括存档是否加载成功，校验和、死亡次数、收藏品数量、成就数量、击败 Mom 的次数以及最佳连胜次数等。





# function parse_savefile_infos(strings)

> 这段代码是一个 JavaScript 函数，用于解析特定格式的存档数据字符串并将其转换为一个包含游戏存档信息的 JavaScript 对象。让我为您解释这段代码的主要部分：
>
> 1. 首先，代码创建一个空对象 `savedata`，用于存储解析后的数据。
>
> 2. 接着，它将输入字符串 `strings` 使用逗号分隔，并将其存储在数组 `strs` 中。
>
> 3. 代码创建一个名为 `buffer` 的二进制数组缓冲区，用于后续的数据读取。
>
> 4. 使用 `DataView` 对象来操作二进制数据，代码将 `strs` 中的每个字符串转换为无符号 8 位整数，并将它们存储到 `buffer` 中。
>
> 5. `cursor` 变量用于跟踪当前读取位置。
>
> 6. 代码定义了几个用于读取不同数据类型的辅助函数，如 `read_uint32` 用于读取无符号 32 位整数，`read_uint16` 用于读取无符号 16 位整数，以及 `read_byte` 用于读取单个字节的整数。
>
> 7. 接下来，代码读取存档的标头部分，其中包括一个长度为 16 字节的字符串。如果这个字符串不等于 "ISAACNGSAVE09R  "，则会弹出一个警告并返回 `undefined`。
>
> 8. 存档的校验和被读取并存储在 `savedata.checksum` 中。
>
> 9. 接下来的部分是一个循环，它根据存档的不同块类型执行不同的处理逻辑。每个块都有一个类型、大小和额外的数字。
>
> 10. 根据块的类型，代码会执行不同的逻辑，例如处理成就数据、统计数据、收藏品数据、挑战数据等等。
>
> 11. 最后，函数返回一个包含解析后的存档数据的 `savedata` 对象。
>
> 总之，这段代码是一个用于解析特定格式存档数据的 JavaScript 函数，它将输入字符串转换为一个包含不同类型游戏数据的对象，以便进一步处理或展示。



> 这段代码是什么意思       (function () {
>            function loadPersistantGameState() {
>                   function parse_savefile_infos(strings) {
>                          var savedata = {}
>                          var strs = strings.split(',')
>                          var buffer = new ArrayBuffer(strs.length)
>                          var dv = new DataView(buffer)
>                          for (var i = 0; i < strs.length; i++) { dv.setUint8(i, +strs[i]) } var cursor = 0
>                          function read_uint32() {
>                                 var r = dv.getUint32(cursor, true)
>                                 cursor += 4
>                                 return r
>                          } function read_uint16() {
>                                 var r = dv.getUint16(cursor, true)
>                                 cursor += 2
>                                 return r
>                          } function read_byte() {
>                                 var r = dv.getUint8(cursor)
>                                 cursor += 1
>                                 return r
>                          } {
>                                 var preleading = ''
>                                 for (var i = 0; i < 16; i++) { preleading += String.fromCharCode(read_byte()) } if (preleading != "ISAACNGSAVE09R  ") {
>                                        alert("您的存档格式不受支持，此功能暂只支持胎衣†/忏悔的存档")
>                                        return undefined
>                                 } savedata.preleading = preleading
>                          } savedata.checksum = read_uint32()
>                          var block_count = 0
>                          while (block_count < 11) {
>                                 block_count++
>                                 var block_type = read_uint32()
>                                 var block_size = read_uint32()
>                                 var extra_number = read_uint32()
>                                 switch (block_type) {
>                                        case 1: var achi_count = extra_number
>                                               var achis = []
>                                               for (var i = 0; i < block_size; i++) {
>                                                      if (i < achi_count) achis.push(read_byte() > 0)
>                                                      else read_byte()
>                                               } savedata.achis = achis
>                                               break
>                                        case 2: var counter = {}
>                                               counter.momkills = dv.getUint32(cursor + 4, true)
>                                               counter.death = dv.getUint32(cursor + 0x28, true)
>                                               counter.beststreak = dv.getUint32(cursor + 0x5c, true)
>                                               savedata.counter = counter
>                                               var counter_data = []
>                                               for (var i = 0; i < block_size; i += 4) { counter_data.push(dv.getUint32(cursor + i, true)) } savedata.counter_data = counter_data
>                                               cursor += block_size
>                                               break
>                                        case 4: var collectibles = []
>                                               for (var i = 0; i < extra_number; i++) { collectibles.push(read_byte() > 0) } savedata.collectibles = collectibles
>                                               break
>                                        case 7: var challenges = []
>                                               for (var i = 0; i < extra_number; i++) { challenges.push(read_byte() > 0) } savedata.challenges = challenges
>                                               break
>                                        case 8: var cutscene = []
>                                               for (var i = 0; i < extra_number; i++) { cutscene.push(read_uint32()) } savedata.cutscene = cutscene
>                                               break
>                                        case 3: var level = []
>                                               for (var i = 0; i < extra_number; i++) { level.push(read_uint32()) } savedata.level = level
>                                               break
>                                        case 9: cursor += block_size
>                                               break
>                                        case 5: case 6: case 10: cursor += extra_number
>                                               break
>                                        case 11: var bestiary = {}
>                                               for (var i = 0; i < 4; i++) {
>                                                      var type = read_uint32()
>                                                      var size = read_uint32() / 4
>                                                      for (var j = 0; j < size; j++) {
>                                                             var SubType = read_byte()
>                                                             var Variant = read_byte()
>                                                             var Type = read_byte()
>                                                             Type += read_byte() << 8
>                                                             Type >>= 4
>                                                             var value = read_uint16()
>                                                             bestiary[Type + "." + Variant] = bestiary[Type + "." + Variant] || {}
>                                                             bestiary[Type + "." + Variant][type] = (bestiary[Type + "." + Variant][type] || 0) + value
>                                                             read_uint16()
>                                                      }
>                                               } savedata.bestiary = bestiary
>                                               break
>                                 }
>                          } return savedata
>                   } var selectors = document.getElementsByClassName('persistentgamedata_selector')
>                   for (var i = 0; i < selectors.length; i++) {
>                          var elem = selectors[i]
>                          var indicator = elem.querySelector('#persistentgamedata_selector_indicator')
>                          var btn = elem.querySelector('#persistentgamedata_selector_loadbtn')
>                          var rmbtn = elem.querySelector('#persistentgamedata_selector_removebtn')
>                          var input = document.createElement('input')
>                          input.setAttribute('type', 'file')
>                          input.setAttribute('accept', '.dat')
>                          input.style = "display:none"
>                          elem.appendChild(input)
>                          function update_indicator(elem) {
>                                 var savedatas = localStorage.getItem('isaac_game_persistentgamedata')
>                                 savedatas = savedatas && parse_savefile_infos(savedatas)
>                                 if (savedatas) {
>                                        indicator.innerHTML = "存档已加载"
>                                        var obj = elem.querySelector('#persistentgamedata_selector_checksum')
>                                        if (obj) { obj.innerHTML = savedatas.checksum.toString(16) } obj = elem.querySelector('#persistentgamedata_selector_death_count')
>                                        if (obj) { obj.innerHTML = savedatas.counter.death } obj = elem.querySelector('#persistentgamedata_selector_collectibles_count')
>                                        if (obj) {
>                                               var count = 0
>                                               for (var i = 1; i < savedatas.collectibles.length; i++) { if (savedatas.collectibles[i]) { count++ } } obj.innerHTML = count
>                                        } obj = elem.querySelector('#persistentgamedata_selector_achievements_count')
>                                        if (obj) {
>                                               var count = 0
>                                               for (var i = 1; i < savedatas.achis.length; i++) { if (savedatas.achis[i]) { count++ } } obj.innerHTML = count
>                                        } obj = elem.querySelector('#persistentgamedata_selector_momkills_count')
>                                        if (obj) { obj.innerHTML = savedatas.counter.momkills } obj = elem.querySelector('#persistentgamedata_selector_beststreak_count')
>                                        if (obj) { obj.innerHTML = savedatas.counter.beststreak }
>                                 } else {
>                                        indicator.innerHTML = "存档未加载"
>                                        var obj = elem.querySelector('#persistentgamedata_selector_checksum')
>                                        if (obj) { obj.innerHTML = '' } obj = elem.querySelector('#persistentgamedata_selector_death_count')
>                                        if (obj) { obj.innerHTML = '' } obj = elem.querySelector('#persistentgamedata_selector_collectibles_count')
>                                        if (obj) { obj.innerHTML = '' } obj = elem.querySelector('#persistentgamedata_selector_achievements_count')
>                                        if (obj) { obj.innerHTML = '' } obj = elem.querySelector('#persistentgamedata_selector_momkills_count')
>                                        if (obj) { obj.innerHTML = '' } obj = elem.querySelector('#persistentgamedata_selector_beststreak_count')
>                                        if (obj) { obj.innerHTML = '' }
>                                 }
>                          } update_indicator(elem)
>                          btn.addEventListener('click', function () { input.click() })
>                          rmbtn.addEventListener('click', function () {
>                                 localStorage.removeItem('isaac_game_persistentgamedata')
>                                 update_indicator(elem)
>                          })
>                          input.addEventListener('input', function () {
>                                 update_indicator(elem)
>                                 if (input.files.length != 1) { return } var file = input.files[0]
>                                 if (file.name.match('((rep)|(abp))_persistentgamedata[0-9]+.dat') == null) { if (!confirm('正确的存档名应该类似rep_persistentgamedata1.dat或abp_persistentgamedata1.dat，您确定要使用' + file.name + '吗？')) { return } } file.arrayBuffer().then(function (arrayBuffer) {
>                                        var array = new Uint8Array(arrayBuffer).toString()
>                                        if (parse_savefile_infos(array) == undefined) { return } localStorage.setItem('isaac_game_persistentgamedata', array)
>                                        update_indicator(elem)
>                                 })
>                          })
>                   } var achievement_data = localStorage.getItem('isaac_game_persistentgamedata')
>                   achievement_data = achievement_data && parse_savefile_infos(achievement_data)
>                   function is_achievement_unlocked(id) { return achievement_data.achis.length > id && achievement_data.achis[id] > 0 } var removes = []
>                   var objs = document.getElementsByClassName('persistentgamedata_achi_unlocked')
>                   for (var i = 0; i < objs.length; i++) {
>                          var aid = objs[i].getAttribute('data-item')
>                          if (typeof (aid) != "string") return
>                          if (!aid.match('^[0-9]+$')) return
>                          if (!achievement_data || !(is_achievement_unlocked(+aid))) { removes.push(objs[i]) }
>                   } objs = document.getElementsByClassName('persistentgamedata_achi_locked')
>                   for (var i = 0; i < objs.length; i++) {
>                          var aid = objs[i].getAttribute('data-item')
>                          if (typeof (aid) != "string") return
>                          if (!aid.match('^[0-9]+$')) return
>                          if (!achievement_data || is_achievement_unlocked(+aid)) { removes.push(objs[i]) }
>                   } objs = document.getElementsByClassName('persistentgamedata_no_achi')
>                   for (var i = 0; i < objs.length; i++) { if (achievement_data) { removes.push(objs[i]) } } objs = document.getElementsByClassName('persistentgamedata_with_achi')
>                   for (var i = 0; i < objs.length; i++) { if (!achievement_data) { removes.push(objs[i]) } } function is_item_unlocked(id) { return achievement_data.collectibles.length > id && achievement_data.collectibles[id] > 0 } var objs = document.getElementsByClassName('persistentgamedata_item_unlocked')
>                   for (var i = 0; i < objs.length; i++) {
>                          var aid = objs[i].getAttribute('data-item')
>                          if (typeof (aid) != "string") return
>                          if (!aid.match('^[0-9]+$')) return
>                          if (!achievement_data || !(is_item_unlocked(+aid))) { removes.push(objs[i]) }
>                   } objs = document.getElementsByClassName('persistentgamedata_item_locked')
>                   for (var i = 0; i < objs.length; i++) {
>                          var aid = objs[i].getAttribute('data-item')
>                          if (typeof (aid) != "string") return
>                          if (!aid.match('^[0-9]+$')) return
>                          if (!achievement_data || is_item_unlocked(+aid)) { removes.push(objs[i]) }
>                   } function is_challenge_unlocked(id) { return achievement_data.challenges.length > id && achievement_data.challenges[id] > 0 } var objs = document.getElementsByClassName('persistentgamedata_challenge_unlocked')
>                   for (var i = 0; i < objs.length; i++) {
>                          var aid = objs[i].getAttribute('data-item')
>                          if (typeof (aid) != "string") return
>                          if (!aid.match('^[0-9]+$')) return
>                          if (!achievement_data || !(is_challenge_unlocked(+aid))) { removes.push(objs[i]) }
>                   } objs = document.getElementsByClassName('persistentgamedata_challenge_locked')
>                   for (var i = 0; i < objs.length; i++) {
>                          var aid = objs[i].getAttribute('data-item')
>                          if (typeof (aid) != "string") return
>                          if (!aid.match('^[0-9]+$')) return
>                          if (!achievement_data || is_challenge_unlocked(+aid)) { removes.push(objs[i]) }
>                   } for (var i = 0; i < removes.length; i++) { removes[i].remove() } if (achievement_data) {
>                          var icons = document.querySelectorAll(".icons.Achievement")
>                          for (var i = 0; i < icons.length; i++) {
>                                 var icon = icons[i]
>                                 var match = icon.id.match('^Achievement_([0-9]+)$')
>                                 if (match) {
>                                        var achievement_id = +match[1]
>                                        if (!is_achievement_unlocked(achievement_id)) {
>                                               var tip = document.createElement('span')
>                                               tip.className = "fa fa-lock"
>                                               tip.style = "position:absolute;left:4px;top:0px;color:#ffeb00;background-color:#0027ff;"
>                                               icon.appendChild(tip)
>                                               icon.style = "filter:grayscale(50%) brightness(50%);" + (icon.style || '')
>                                        }
>                                 }
>                          }
>                   } if (achievement_data) {
>                          objs = document.getElementsByClassName('persistentgamedata_bestiary')
>                          for (var i = 0; i < objs.length; i++) {
>                                 var elem = objs[i]
>                                 var type_data = elem.getAttribute('data-item')
>                                 var propattr_data = elem.getAttribute('data-propattr')
>                                 if (typeof (type_data) != "string" || typeof (propattr_data) != "string") continue
>                                 if (!type_data.match('^[0-9]+\.[0-9]+$')) continue
>                                 if (propattr_data != '1' && propattr_data != '2' && propattr_data != '3' && propattr_data != '4') continue
>                                 var data = achievement_data.bestiary && achievement_data.bestiary[type_data]
>                                 var result_text = data ? (data[propattr_data] || 0) : 0
>                                 elem.innerHTML = result_text
>                          } objs = document.getElementsByClassName('persistentgamedata_counter_data')
>                          for (var i = 0; i < objs.length; i++) {
>                                 var elem = objs[i]
>                                 var type_data = elem.getAttribute('data-item')
>                                 if (typeof (type_data) != "string") continue
>                                 if (!type_data.match('^[0-9]+$')) continue
>                                 if (achievement_data.counter_data && (+type_data < achievement_data.counter_data.length)) { elem.innerHTML = achievement_data.counter_data[+type_data] } else { elem.innerHTML = '-' }
>                          } objs = document.getElementsByClassName('persistentgamedata_cutscene_data')
>                          for (var i = 0; i < objs.length; i++) {
>                                 var elem = objs[i]
>                                 var type_data = elem.getAttribute('data-item')
>                                 if (typeof (type_data) != "string") continue
>                                 if (!type_data.match('^[0-9]+$')) continue
>                                 if (achievement_data.cutscene && (+type_data < achievement_data.cutscene.length)) { elem.innerHTML = achievement_data.cutscene[+type_data] } else { elem.innerHTML = '-' }
>                          } objs = document.getElementsByClassName('persistentgamedata_level_data')
>                          for (var i = 0; i < objs.length; i++) {
>                                 var elem = objs[i]
>                                 var type_data = elem.getAttribute('data-item')
>                                 if (typeof (type_data) != "string") continue
>                                 if (!type_data.match('^[0-9]+$')) continue
>                                 if (achievement_data.level && (+type_data < achievement_data.level.length)) { elem.innerHTML = achievement_data.level[+type_data] } else { elem.innerHTML = '-' }
>                          }
>                   }
>            } if (document.readyState == 'loading') { document.addEventListener('DOMContentLoaded', loadPersistantGameState) } else { loadPersistantGameState() }
>     })()

这段代码是一段JavaScript代码，看起来是为了处理游戏存档数据和与用户界面的交互。以下是对代码的主要功能的解释：

1. `loadPersistantGameState` 函数：这是一个定义了处理游戏存档数据的函数。

2. `parse_savefile_infos` 函数：这个函数用于解析游戏存档数据字符串并将其转换为JavaScript对象。它按照特定的格式读取存档数据中的各种信息，例如成就、计数器、物品等。

3. 页面元素选择：代码中通过 `document.getElementsByClassName` 获取了一些页面元素，用于与用户界面交互，如选择存档、加载按钮等。

4. 存档数据处理：代码中处理了存档数据，包括存档已加载的指示、存档信息的显示、存档的加载和删除等功能。

5. 解锁状态判断：根据存档数据，代码判断了成就、物品和挑战的解锁状态，并根据解锁状态显示或隐藏相关的页面元素。

6. 更新页面元素：根据存档数据，代码更新了页面上的一些元素，显示了成就进度、物品解锁状态、计数器数据等。

7. 事件监听：代码添加了一些事件监听器，例如点击按钮触发文件选择、点击删除按钮清除存档数据等。

总的来说，这段代码的主要目的是处理游戏存档数据，并在用户界面上显示相关信息和状态。它还负责处理用户与存档数据的交互，允许用户加载、删除存档，并显示与存档相关的信息。

---

> 这段代码什么意思 var array = new Uint8Array(arrayBuffer).toString()

这段代码的目的是将一个 `Uint8Array` 数组转换为字符串。让我来解释每个部分的含义：

1. `new Uint8Array(arrayBuffer)`: 这部分代码创建了一个名为 `array` 的 `Uint8Array` 数组，其中 `arrayBuffer` 是一个二进制数据缓冲区（`ArrayBuffer`），通常包含了一系列无符号8位整数（字节）。`Uint8Array` 表示一个包含无符号8位整数的数组，也就是字节数组。

2. `.toString()`: 一旦创建了 `Uint8Array` 数组，代码调用了 `toString()` 方法来将这个字节数组转换为字符串。这是 JavaScript 中的默认 `toString` 方法，它会尝试将数组的内容按照默认编码转换为字符串。

总之，这段代码的作用是将一个二进制数据数组（字节数组）转换为字符串，但是需要注意的是，转换的结果可能不会是人类可读的文本，而可能是包含非可打印字符的二进制数据表示形式。具体的输出取决于数组中包含的字节内容以及默认的编码方式。如果要将字节数据正确地转换为文本，通常需要指定正确的字符编码方式，例如 UTF-8。