function parse_savefile_infos(strings) {
    var savedata = {};
    var strs = strings.split(",");
    var buffer = new ArrayBuffer(strs.length);
    var dv = new DataView(buffer);
    for (var i = 0; i < strs.length; i++) {
        dv.setUint8(i, +strs[i]);
    }
    var cursor = 0;
    function read_uint32() {
        var r = dv.getUint32(cursor, true);
        cursor += 4;
        return r;
    }
    function read_uint16() {
        var r = dv.getUint16(cursor, true);
        cursor += 2;
        return r;
    }
    function read_byte() {
        var r = dv.getUint8(cursor);
        cursor += 1;
        return r;
    }
    {
        var preleading = "";
        for (var i = 0; i < 16; i++) {
            preleading += String.fromCharCode(read_byte());
        }
        if (preleading != "ISAACNGSAVE09R  ") {
            alert("您的存档格式不受支持，此功能暂只支持胎衣†/忏悔的存档");
            return undefined;
        }
        savedata["preleading"] = preleading;
    }
    savedata["checksum"] = read_uint32();
    var block_count = 0;
    while (block_count < 11) {
        block_count++;
        var block_type = read_uint32();
        var block_size = read_uint32();
        var extra_number = read_uint32();
        switch (block_type) {
            case 1:
                var achi_count = extra_number;
                var achis = [];
                for (var i = 0; i < block_size; i++) {
                    if (i < achi_count)
                        achis.push(read_byte() > 0);
                    else
                        read_byte();
                }
                savedata["achis"] = achis;
                break;
            case 2:
                var counter = {};
                counter["momkills"] = dv.getUint32(cursor + 4, true);
                counter["death"] = dv.getUint32(cursor + 0x28, true);
                counter["beststreak"] = dv.getUint32(cursor + 0x5c, true);
                savedata["counter"] = counter;
                var counter_data = [];
                for (var i = 0; i < block_size; i += 4) {
                    counter_data.push(dv.getUint32(cursor + i, true));
                }
                savedata["counter_data"] = counter_data;
                cursor += block_size;
                break;
            case 4:
                var collectibles = [];
                for (var i = 0; i < extra_number; i++) {
                    collectibles.push(read_byte() > 0);
                }
                savedata["collectibles"] = collectibles;
                break;
            case 7:
                var challenges = [];
                for (var i = 0; i < extra_number; i++) {
                    challenges.push(read_byte() > 0);
                }
                savedata["challenges"] = challenges;
                break;
            case 8:
                var cutscene = [];
                for (var i = 0; i < extra_number; i++) {
                    cutscene.push(read_uint32());
                }
                savedata["cutscene"] = cutscene;
                break;
            case 3:
                var level = [];
                for (var i = 0; i < extra_number; i++) {
                    level.push(read_uint32());
                }
                savedata["level"] = level;
                break;
            case 9:
                cursor += block_size;
                break;
            case 5:
            case 6:
            case 10:
                cursor += extra_number;
                break;
            case 11:
                var bestiary = {};
                for (var i = 0; i < 4; i++) {
                    var type = read_uint32();
                    var size = read_uint32() / 4;
                    for (var j = 0; j < size; j++) {
                        var SubType = read_byte();
                        var Variant = read_byte();
                        var Type = read_byte();
                        Type += read_byte() << 8;
                        Type >>= 4;
                        var value = read_uint16();
                        bestiary[Type + "." + Variant] =
                            bestiary[Type + "." + Variant] || {};
                        bestiary[Type + "." + Variant][type] =
                            (bestiary[Type + "." + Variant][type] || 0) + value;
                        read_uint16();
                    }
                }
                savedata["bestiary"] = bestiary;
                break;
        }
    }
    return savedata;
}
var data = "73,83,65,65,67,78,71,83,65,86,69,48,57,82,32,32,93,150,51,254,1,0,0,0,126,2,0,0,126,2,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,2,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,1,0,0,1,1,0,1,1,0,0,1,0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,1,0,0,1,0,1,1,0,0,0,0,0,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,192,7,0,0,240,1,0,0,0,0,0,0,66,0,0,0,60,42,0,0,223,0,0,0,4,0,0,0,22,21,0,0,212,4,0,0,18,0,0,0,0,0,0,0,79,0,0,0,56,0,0,0,23,0,0,0,104,1,0,0,23,0,0,0,188,0,0,0,95,0,0,0,183,1,0,0,87,2,0,0,22,0,0,0,0,0,0,0,9,3,0,0,99,0,0,0,3,0,0,0,7,0,0,0,17,0,0,0,16,0,0,0,3,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2,0,0,0,1,0,0,0,2,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,2,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,232,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,7,0,0,0,140,0,0,0,47,0,0,0,1,0,0,0,173,0,0,0,0,0,0,0,3,0,0,0,16,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,104,2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,132,1,0,0,113,3,0,0,89,7,0,0,35,3,0,0,245,3,0,0,20,0,0,0,5,0,0,0,5,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,21,0,0,0,1,0,0,0,4,0,0,0,3,0,0,0,56,0,0,0,14,0,0,0,0,0,0,0,138,0,0,0,127,0,0,0,90,0,0,0,89,0,0,0,74,0,0,0,91,0,0,0,69,0,0,0,66,0,0,0,7,0,0,0,46,0,0,0,36,0,0,0,29,0,0,0,0,0,0,0,4,0,0,0,116,11,0,0,221,2,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,0,0,1,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1,0,1,1,0,1,1,0,1,0,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,1,0,1,1,1,1,1,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,5,0,0,0,28,0,0,0,7,0,0,0,1,1,1,1,1,1,1,6,0,0,0,160,1,0,0,104,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,0,0,0,1,1,0,7,0,0,0,184,0,0,0,46,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,8,0,0,0,108,0,0,0,27,0,0,0,0,0,0,0,0,0,0,0,93,0,0,0,3,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,3,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,5,0,0,0,4,0,0,0,13,0,0,0,11,0,0,0,3,0,0,0,1,0,0,0,18,0,0,0,8,0,0,0,13,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,8,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,64,1,0,0,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,204,18,0,0,4,0,0,0,4,0,0,0,44,1,0,0,0,0,160,0,1,0,0,0,0,2,160,0,1,0,0,0,0,0,176,0,1,0,0,0,0,1,224,0,1,0,0,0,0,2,240,0,1,0,0,0,0,0,64,1,3,0,0,0,0,0,128,1,1,0,0,0,0,0,144,1,1,0,0,0,0,1,144,1,1,0,0,0,0,0,160,1,1,0,0,0,0,0,176,1,2,0,0,0,0,0,192,1,1,0,0,0,0,0,224,1,1,0,0,0,0,0,32,2,1,0,0,0,0,0,96,2,1,0,0,0,0,1,112,2,1,0,0,0,0,3,112,2,1,0,0,0,0,2,160,2,2,0,0,0,0,0,176,2,1,0,0,0,0,0,240,2,2,0,0,0,0,0,64,3,1,0,0,0,0,0,96,3,2,0,0,0,0,1,112,3,1,0,0,0,0,0,128,3,1,0,0,0,0,0,208,3,2,0,0,0,0,3,208,3,1,0,0,0,0,0,224,3,1,0,0,0,0,3,224,3,1,0,0,0,0,0,0,4,1,0,0,0,0,0,64,4,2,0,0,0,0,0,224,4,2,0,0,0,0,1,224,4,2,0,0,0,0,1,240,4,1,0,0,0,0,10,240,4,1,0,0,0,0,12,240,4,1,0,0,0,0,0,16,5,3,0,0,0,0,0,80,5,4,0,0,0,0,0,128,5,1,0,0,0,0,0,144,5,1,0,0,0,0,0,48,6,1,0,0,0,0,0,64,6,2,0,0,0,0,1,64,6,1,0,0,0,0,0,96,6,3,0,0,0,0,1,96,6,1,0,0,0,0,0,240,12,1,0,0,0,0,1,240,12,1,0,0,0,0,0,96,13,1,0,0,0,0,0,144,13,1,0,0,0,0,0,160,13,2,0,0,0,0,0,192,13,1,0,0,0,0,2,32,14,1,0,0,0,0,0,80,14,1,0,0,0,0,1,208,14,1,0,0,0,0,0,64,15,1,0,0,0,0,0,208,15,1,0,0,0,0,0,48,16,3,0,0,0,0,10,64,16,1,0,0,0,0,1,80,16,1,0,0,0,0,0,96,16,2,0,0,0,0,0,128,16,2,0,0,0,0,0,144,16,2,0,0,0,0,0,16,17,3,0,0,0,0,0,192,17,1,0,0,0,0,0,16,25,1,0,0,0,0,0,64,25,1,0,0,0,0,0,112,25,1,0,0,0,0,0,128,50,3,0,0,0,0,0,192,50,1,0,0,0,0,0,96,52,1,0,0,0,0,0,80,56,1,0,0,0,0,0,96,56,3,0,0,0,0,0,144,56,1,0,0,0,0,0,0,57,2,0,0,0,0,0,64,57,2,0,0,0,0,0,80,57,1,0,0,0,2,0,0,0,124,6,0,0,0,0,160,0,64,1,0,0,0,1,160,0,192,0,0,0,0,2,160,0,133,0,0,0,0,3,160,0,169,0,0,0,0,0,176,0,213,2,0,0,0,1,176,0,185,1,0,0,0,0,192,0,255,1,0,0,0,0,208,0,79,6,0,0,0,0,224,0,106,3,0,0,0,1,224,0,190,0,0,0,0,0,240,0,38,2,0,0,0,1,240,0,56,1,0,0,0,2,240,0,127,0,0,0,0,3,240,0,42,0,0,0,0,0,0,1,132,0,0,0,0,1,0,1,88,0,0,0,0,2,0,1,107,0,0,0,0,0,32,1,77,17,0,0,0,0,48,1,175,2,0,0,0,1,48,1,164,2,0,0,0,2,48,1,64,0,0,0,0,0,64,1,129,0,0,0,0,0,80,1,14,2,0,0,0,0,96,1,52,1,0,0,0,1,96,1,51,0,0,0,0,2,96,1,42,0,0,0,0,0,112,1,88,6,0,0,0,1,112,1,23,1,0,0,0,2,112,1,114,0,0,0,0,3,112,1,9,0,0,0,0,0,128,1,87,2,0,0,0,1,128,1,251,0,0,0,0,2,128,1,80,0,0,0,0,3,128,1,205,0,0,0,0,0,144,1,61,3,0,0,0,1,144,1,25,1,0,0,0,2,144,1,119,0,0,0,0,3,144,1,47,0,0,0,0,4,144,1,16,0,0,0,0,5,144,1,34,0,0,0,0,0,160,1,139,2,0,0,0,1,160,1,175,1,0,0,0,2,160,1,124,0,0,0,0,0,176,1,34,2,0,0,0,1,176,1,161,0,0,0,0,3,176,1,31,0,0,0,0,0,192,1,3,1,0,0,0,1,192,1,42,0,0,0,0,2,192,1,78,0,0,0,0,0,208,1,241,1,0,0,0,1,208,1,114,1,0,0,0,2,208,1,125,0,0,0,0,0,224,1,1,2,0,0,0,1,224,1,41,0,0,0,0,2,224,1,68,1,0,0,0,0,240,1,51,1,0,0,0,0,0,2,161,2,0,0,0,0,32,2,97,1,0,0,0,1,32,2,91,0,0,0,0,0,64,2,18,0,0,0,0,0,96,2,213,1,0,0,0,1,96,2,2,1,0,0,0,2,96,2,7,0,0,0,0,3,96,2,145,0,0,0,0,0,112,2,162,1,0,0,0,1,112,2,110,0,0,0,0,2,112,2,185,0,0,0,0,3,112,2,87,0,0,0,0,0,128,2,26,2,0,0,0,1,128,2,62,0,0,0,0,2,128,2,50,0,0,0,0,0,144,2,234,1,0,0,0,1,144,2,118,0,0,0,0,3,144,2,48,0,0,0,0,0,160,2,3,0,0,0,0,0,176,2,67,0,0,0,0,1,176,2,13,0,0,0,0,0,192,2,9,0,0,0,0,0,224,2,68,0,0,0,0,1,224,2,46,0,0,0,0,2,224,2,14,0,0,0,0,0,240,2,63,0,0,0,0,1,240,2,27,0,0,0,0,0,0,3,72,0,0,0,0,1,0,3,57,0,0,0,0,0,16,3,46,0,0,0,0,1,16,3,22,0,0,0,0,0,32,3,184,0,0,0,0,1,32,3,91,0,0,0,0,0,48,3,47,0,0,0,0,1,48,3,25,0,0,0,0,0,64,3,42,0,0,0,0,1,64,3,24,0,0,0,0,0,80,3,36,0,0,0,0,1,80,3,19,0,0,0,0,0,96,3,71,0,0,0,0,0,112,3,228,0,0,0,0,1,112,3,29,1,0,0,0,2,112,3,129,0,0,0,0,0,128,3,134,1,0,0,0,0,144,3,101,0,0,0,0,1,144,3,64,0,0,0,0,2,144,3,3,0,0,0,0,0,160,3,179,2,0,0,0,1,160,3,161,0,0,0,0,0,176,3,173,0,0,0,0,0,192,3,127,1,0,0,0,1,192,3,77,0,0,0,0,2,192,3,28,0,0,0,0,0,208,3,157,2,0,0,0,1,208,3,78,0,0,0,0,2,208,3,193,0,0,0,0,3,208,3,139,0,0,0,0,4,208,3,14,0,0,0,0,5,208,3,243,0,0,0,0,0,224,3,122,1,0,0,0,1,224,3,216,0,0,0,0,2,224,3,26,1,0,0,0,3,224,3,28,0,0,0,0,0,240,3,54,0,0,0,0,0,0,4,45,0,0,0,0,1,16,4,74,0,0,0,0,0,32,4,3,0,0,0,0,0,48,4,87,0,0,0,0,1,48,4,51,0,0,0,0,0,64,4,33,0,0,0,0,1,64,4,56,0,0,0,0,0,80,4,65,0,0,0,0,1,80,4,56,0,0,0,0,0,112,4,65,0,0,0,0,1,112,4,28,0,0,0,0,0,160,4,14,0,0,0,0,0,208,4,179,1,0,0,0,0,224,4,21,0,0,0,0,1,224,4,58,0,0,0,0,0,240,4,55,0,0,0,0,1,240,4,20,0,0,0,0,2,240,4,41,0,0,0,0,10,240,4,53,0,0,0,0,11,240,4,18,0,0,0,0,12,240,4,43,0,0,0,0,0,0,5,225,0,0,0,0,0,16,5,229,0,0,0,0,1,16,5,41,0,0,0,0,0,32,5,34,0,0,0,0,0,48,5,90,0,0,0,0,0,64,5,1,0,0,0,0,0,80,5,161,15,0,0,0,0,96,5,234,3,0,0,0,0,112,5,173,0,0,0,0,1,112,5,17,0,0,0,0,0,128,5,166,0,0,0,0,1,128,5,87,0,0,0,0,2,128,5,46,0,0,0,0,0,144,5,136,1,0,0,0,0,160,5,156,0,0,0,0,0,176,5,52,0,0,0,0,0,192,5,67,1,0,0,0,1,192,5,24,0,0,0,0,0,208,5,2,1,0,0,0,1,208,5,10,0,0,0,0,0,224,5,167,1,0,0,0,0,0,6,4,0,0,0,0,0,16,6,35,0,0,0,0,0,32,6,37,0,0,0,0,0,48,6,95,0,0,0,0,0,64,6,58,0,0,0,0,1,64,6,48,0,0,0,0,0,80,6,18,0,0,0,0,1,80,6,3,0,0,0,0,0,96,6,25,0,0,0,0,1,96,6,19,0,0,0,0,10,160,12,2,0,0,0,0,0,192,12,108,0,0,0,0,0,208,12,106,0,0,0,0,0,224,12,15,0,0,0,0,1,224,12,26,0,0,0,0,0,240,12,49,0,0,0,0,1,240,12,70,0,0,0,0,0,0,13,181,1,0,0,0,1,0,13,25,1,0,0,0,2,0,13,102,0,0,0,0,0,16,13,127,0,0,0,0,0,32,13,149,0,0,0,0,0,48,13,198,0,0,0,0,0,64,13,7,0,0,0,0,1,64,13,191,0,0,0,0,2,64,13,1,0,0,0,0,0,80,13,112,0,0,0,0,0,96,13,101,0,0,0,0,0,112,13,99,0,0,0,0,0,128,13,241,0,0,0,0,0,144,13,122,10,0,0,0,1,144,13,180,0,0,0,0,2,144,13,253,2,0,0,0,0,160,13,1,0,0,0,0,0,176,13,245,0,0,0,0,0,192,13,55,2,0,0,0,1,192,13,96,0,0,0,0,0,208,13,46,0,0,0,0,0,224,13,90,1,0,0,0,0,240,13,118,0,0,0,0,0,0,14,62,0,0,0,0,0,16,14,61,0,0,0,0,0,32,14,105,0,0,0,0,1,32,14,74,0,0,0,0,2,32,14,145,0,0,0,0,0,48,14,46,3,0,0,0,1,48,14,12,0,0,0,0,0,64,14,203,0,0,0,0,0,80,14,84,1,0,0,0,1,80,14,37,0,0,0,0,0,96,14,41,0,0,0,0,0,112,14,14,2,0,0,0,1,112,14,55,0,0,0,0,0,160,14,139,1,0,0,0,0,192,14,1,0,0,0,0,0,208,14,150,0,0,0,0,1,208,14,110,0,0,0,0,2,208,14,40,0,0,0,0,0,224,14,99,0,0,0,0,0,240,14,161,1,0,0,0,0,0,15,101,1,0,0,0,1,0,15,31,0,0,0,0,0,16,15,181,0,0,0,0,0,32,15,144,0,0,0,0,0,48,15,199,0,0,0,0,0,64,15,182,2,0,0,0,1,64,15,62,0,0,0,0,0,96,15,90,0,0,0,0,0,112,15,93,0,0,0,0,0,128,15,86,0,0,0,0,0,144,15,111,0,0,0,0,0,160,15,95,0,0,0,0,0,176,15,97,0,0,0,0,0,192,15,106,1,0,0,0,0,208,15,50,0,0,0,0,0,224,15,3,1,0,0,0,0,240,15,180,0,0,0,0,0,0,16,1,2,0,0,0,0,16,16,67,0,0,0,0,1,16,16,28,0,0,0,0,0,32,16,159,0,0,0,0,0,48,16,151,0,0,0,0,0,64,16,35,0,0,0,0,10,64,16,158,1,0,0,0,0,80,16,77,0,0,0,0,1,80,16,36,0,0,0,0,0,96,16,29,0,0,0,0,0,112,16,48,0,0,0,0,0,128,16,41,0,0,0,0,0,144,16,53,0,0,0,0,0,160,16,9,0,0,0,0,0,176,16,40,0,0,0,0,0,192,16,19,0,0,0,0,0,208,16,79,0,0,0,0,1,208,16,12,0,0,0,0,0,224,16,13,0,0,0,0,0,240,16,23,0,0,0,0,1,240,16,3,0,0,0,0,0,0,17,18,0,0,0,0,1,0,17,3,0,0,0,0,0,16,17,17,0,0,0,0,0,32,17,3,0,0,0,0,0,48,17,3,0,0,0,0,0,64,17,79,0,0,0,0,0,80,17,171,0,0,0,0,0,96,17,64,0,0,0,0,0,112,17,160,0,0,0,0,0,128,17,171,0,0,0,0,0,144,17,79,1,0,0,0,0,160,17,124,0,0,0,0,0,176,17,116,0,0,0,0,0,192,17,240,0,0,0,0,0,208,17,151,0,0,0,0,0,224,17,127,0,0,0,0,0,240,17,57,0,0,0,0,0,0,18,92,0,0,0,0,0,16,18,170,0,0,0,0,0,112,18,65,0,0,0,0,0,128,18,35,2,0,0,0,0,144,18,173,0,0,0,0,0,160,18,23,0,0,0,0,0,176,18,60,1,0,0,0,0,192,18,165,0,0,0,0,0,208,18,83,0,0,0,0,0,224,18,4,0,0,0,0,0,240,18,107,0,0,0,0,0,0,19,66,0,0,0,0,0,16,19,175,0,0,0,0,0,32,19,14,0,0,0,0,1,32,19,14,0,0,0,0,0,48,19,44,0,0,0,0,0,64,19,70,0,0,0,0,0,80,19,38,0,0,0,0,0,96,19,15,0,0,0,0,1,96,19,49,0,0,0,0,0,112,19,96,0,0,0,0,0,16,25,67,0,0,0,0,0,32,25,1,0,0,0,0,0,48,25,41,0,0,0,0,0,64,25,72,0,0,0,0,0,80,25,100,0,0,0,0,0,96,25,39,0,0,0,0,1,96,25,18,0,0,0,0,0,112,25,8,0,0,0,0,0,144,25,26,0,0,0,0,0,160,25,56,0,0,0,0,0,176,25,22,0,0,0,0,0,192,25,8,0,0,0,0,0,80,50,52,0,0,0,0,0,96,50,40,0,0,0,0,0,112,50,114,0,0,0,0,0,128,50,119,1,0,0,0,0,160,50,30,1,0,0,0,0,176,50,26,0,0,0,0,0,192,50,38,0,0,0,0,0,208,50,24,0,0,0,0,0,224,50,179,0,0,0,0,0,240,50,30,0,0,0,0,0,0,51,77,0,0,0,0,1,0,51,30,0,0,0,0,0,16,51,19,0,0,0,0,1,16,51,9,0,0,0,0,1,32,51,6,0,0,0,0,2,32,51,24,0,0,0,0,0,48,51,87,0,0,0,0,0,64,51,38,0,0,0,0,1,64,51,4,0,0,0,0,0,80,51,28,0,0,0,0,0,96,51,44,0,0,0,0,0,112,51,35,0,0,0,0,0,128,51,40,0,0,0,0,1,128,51,2,0,0,0,0,0,144,51,56,0,0,0,0,0,160,51,15,0,0,0,0,0,176,51,66,0,0,0,0,0,192,51,4,0,0,0,0,0,208,51,64,0,0,0,0,0,224,51,6,0,0,0,0,0,240,51,8,0,0,0,0,20,240,51,15,0,0,0,0,1,0,52,12,0,0,0,0,0,16,52,139,0,0,0,0,0,32,52,123,0,0,0,0,1,32,52,52,0,0,0,0,2,32,52,2,0,0,0,0,0,48,52,49,0,0,0,0,0,64,52,30,0,0,0,0,0,96,52,8,0,0,0,0,0,128,52,72,0,0,0,0,0,144,52,10,0,0,0,0,1,144,52,1,0,0,0,0,0,192,52,2,0,0,0,0,1,32,53,43,0,0,0,0,2,32,53,25,0,0,0,0,0,48,53,51,0,0,0,0,0,64,53,25,0,0,0,0,0,80,53,170,1,0,0,0,0,96,53,11,0,0,0,0,0,112,53,61,0,0,0,0,0,128,53,12,0,0,0,0,0,144,53,11,0,0,0,0,0,176,53,39,0,0,0,0,0,192,53,17,0,0,0,0,0,208,53,32,0,0,0,0,0,224,53,18,0,0,0,0,0,240,53,6,0,0,0,0,0,0,54,5,0,0,0,0,0,16,54,19,0,0,0,0,0,64,54,118,2,0,0,0,0,80,54,70,0,0,0,0,0,96,54,51,0,0,0,0,0,112,54,8,0,0,0,0,0,128,54,8,0,0,0,0,0,144,54,8,0,0,0,0,0,160,54,2,0,0,0,0,0,176,54,8,0,0,0,0,1,192,54,2,0,0,0,0,0,224,54,69,0,0,0,0,0,240,54,68,0,0,0,0,0,0,55,18,0,0,0,0,0,16,55,202,1,0,0,0,1,16,55,4,0,0,0,0,0,32,55,3,0,0,0,0,0,48,55,36,0,0,0,0,0,64,55,94,8,0,0,0,0,80,55,17,0,0,0,0,1,80,55,3,0,0,0,0,0,96,55,12,0,0,0,0,1,96,55,14,0,0,0,0,0,128,55,25,0,0,0,0,0,144,55,3,0,0,0,0,0,160,55,4,0,0,0,0,0,176,55,24,0,0,0,0,1,176,55,2,0,0,0,0,0,192,55,8,0,0,0,0,0,64,56,12,0,0,0,0,0,80,56,16,0,0,0,0,0,96,56,11,0,0,0,0,0,128,56,3,0,0,0,0,0,144,56,7,0,0,0,0,0,160,56,4,0,0,0,0,0,192,56,23,0,0,0,0,0,208,56,4,0,0,0,0,0,240,56,3,0,0,0,0,0,0,57,13,0,0,0,0,0,16,57,11,0,0,0,0,0,32,57,2,0,0,0,0,0,48,57,1,0,0,0,0,0,64,57,14,0,0,0,0,0,80,57,2,0,0,0,0,0,96,57,8,0,0,0,0,0,128,57,1,0,0,0,0,0,144,57,1,0,0,0,3,0,0,0,60,4,0,0,0,0,160,0,11,0,0,0,0,1,160,0,3,0,0,0,0,2,160,0,7,0,0,0,0,3,160,0,2,0,0,0,0,0,176,0,5,0,0,0,0,1,176,0,3,0,0,0,0,1,240,0,1,0,0,0,0,2,0,1,13,0,0,0,0,0,32,1,27,0,0,0,0,0,48,1,20,0,0,0,0,1,48,1,8,0,0,0,0,2,48,1,2,0,0,0,0,0,64,1,16,0,0,0,0,0,80,1,1,0,0,0,0,0,112,1,44,0,0,0,0,1,112,1,5,0,0,0,0,2,112,1,9,0,0,0,0,3,112,1,1,0,0,0,0,0,128,1,17,0,0,0,0,1,128,1,12,0,0,0,0,2,128,1,4,0,0,0,0,0,144,1,34,0,0,0,0,1,144,1,2,0,0,0,0,2,144,1,3,0,0,0,0,5,144,1,1,0,0,0,0,0,160,1,8,0,0,0,0,1,160,1,6,0,0,0,0,3,176,1,2,0,0,0,0,0,192,1,11,0,0,0,0,2,192,1,9,0,0,0,0,0,208,1,14,0,0,0,0,1,208,1,17,0,0,0,0,0,224,1,1,0,0,0,0,1,224,1,1,0,0,0,0,0,0,2,1,0,0,0,0,0,32,2,7,0,0,0,0,1,32,2,5,0,0,0,0,0,48,2,19,0,0,0,0,2,48,2,8,0,0,0,0,0,64,2,1,0,0,0,0,1,96,2,1,0,0,0,0,3,96,2,4,0,0,0,0,0,112,2,11,0,0,0,0,1,112,2,7,0,0,0,0,2,112,2,1,0,0,0,0,3,112,2,9,0,0,0,0,0,128,2,4,0,0,0,0,1,128,2,3,0,0,0,0,2,128,2,6,0,0,0,0,0,144,2,9,0,0,0,0,1,144,2,3,0,0,0,0,3,144,2,2,0,0,0,0,0,176,2,26,0,0,0,0,1,176,2,3,0,0,0,0,0,192,2,10,0,0,0,0,1,192,2,7,0,0,0,0,0,208,2,27,0,0,0,0,0,224,2,1,0,0,0,0,1,224,2,2,0,0,0,0,2,224,2,1,0,0,0,0,0,240,2,12,0,0,0,0,1,240,2,4,0,0,0,0,0,0,3,2,0,0,0,0,1,0,3,1,0,0,0,0,1,16,3,2,0,0,0,0,0,32,3,2,0,0,0,0,0,64,3,1,0,0,0,0,1,64,3,3,0,0,0,0,0,96,3,4,0,0,0,0,0,112,3,6,0,0,0,0,1,112,3,20,0,0,0,0,2,112,3,13,0,0,0,0,0,160,3,12,0,0,0,0,1,160,3,4,0,0,0,0,0,192,3,16,0,0,0,0,1,192,3,12,0,0,0,0,0,208,3,6,0,0,0,0,1,208,3,1,0,0,0,0,3,208,3,1,0,0,0,0,0,224,3,18,0,0,0,0,1,224,3,7,0,0,0,0,2,224,3,5,0,0,0,0,3,224,3,4,0,0,0,0,0,240,3,2,0,0,0,0,0,0,4,2,0,0,0,0,1,16,4,1,0,0,0,0,1,64,4,28,0,0,0,0,1,80,4,2,0,0,0,0,0,160,4,3,0,0,0,0,0,208,4,1,0,0,0,0,0,224,4,1,0,0,0,0,1,224,4,2,0,0,0,0,0,240,4,2,0,0,0,0,1,240,4,1,0,0,0,0,2,240,4,7,0,0,0,0,10,240,4,5,0,0,0,0,11,240,4,12,0,0,0,0,12,240,4,8,0,0,0,0,0,0,5,2,0,0,0,0,0,16,5,17,0,0,0,0,1,16,5,18,0,0,0,0,0,32,5,6,0,0,0,0,0,48,5,1,0,0,0,0,0,64,5,4,0,0,0,0,0,80,5,121,0,0,0,0,0,96,5,5,0,0,0,0,0,112,5,6,0,0,0,0,1,112,5,2,0,0,0,0,0,128,5,1,0,0,0,0,1,128,5,1,0,0,0,0,0,144,5,7,0,0,0,0,0,208,5,18,0,0,0,0,1,208,5,1,0,0,0,0,0,224,5,17,0,0,0,0,0,0,6,3,0,0,0,0,0,16,6,13,0,0,0,0,0,32,6,1,0,0,0,0,0,48,6,31,0,0,0,0,0,64,6,16,0,0,0,0,1,64,6,5,0,0,0,0,0,80,6,10,0,0,0,0,0,96,6,1,0,0,0,0,1,96,6,3,0,0,0,0,0,144,12,4,0,0,0,0,0,176,12,2,0,0,0,0,0,192,12,5,0,0,0,0,1,224,12,2,0,0,0,0,0,240,12,1,0,0,0,0,1,240,12,8,0,0,0,0,1,0,13,2,0,0,0,0,0,16,13,3,0,0,0,0,0,32,13,2,0,0,0,0,0,64,13,16,0,0,0,0,1,64,13,3,0,0,0,0,3,64,13,1,0,0,0,0,0,80,13,2,0,0,0,0,0,96,13,2,0,0,0,0,0,112,13,6,0,0,0,0,0,128,13,2,0,0,0,0,0,144,13,17,0,0,0,0,1,144,13,3,0,0,0,0,2,144,13,4,0,0,0,0,0,160,13,15,0,0,0,0,0,176,13,16,0,0,0,0,0,192,13,12,0,0,0,0,1,192,13,5,0,0,0,0,0,224,13,6,0,0,0,0,0,0,14,1,0,0,0,0,0,16,14,6,0,0,0,0,0,32,14,2,0,0,0,0,1,32,14,2,0,0,0,0,2,32,14,12,0,0,0,0,0,48,14,4,0,0,0,0,0,64,14,4,0,0,0,0,0,96,14,9,0,0,0,0,0,112,14,1,0,0,0,0,1,112,14,1,0,0,0,0,0,160,14,9,0,0,0,0,0,208,14,3,0,0,0,0,1,208,14,22,0,0,0,0,2,208,14,3,0,0,0,0,0,240,14,3,0,0,0,0,0,0,15,1,0,0,0,0,0,16,15,23,0,0,0,0,0,64,15,4,0,0,0,0,0,96,15,3,0,0,0,0,0,144,15,4,0,0,0,0,0,160,15,12,0,0,0,0,0,176,15,3,0,0,0,0,0,192,15,7,0,0,0,0,0,224,15,2,0,0,0,0,0,240,15,2,0,0,0,0,0,0,16,12,0,0,0,0,0,32,16,1,0,0,0,0,0,48,16,1,0,0,0,0,0,64,16,3,0,0,0,0,10,64,16,15,0,0,0,0,0,80,16,26,0,0,0,0,1,80,16,6,0,0,0,0,0,112,16,4,0,0,0,0,0,128,16,15,0,0,0,0,0,144,16,23,0,0,0,0,0,176,16,20,0,0,0,0,0,192,16,10,0,0,0,0,0,208,16,4,0,0,0,0,1,208,16,2,0,0,0,0,0,240,16,5,0,0,0,0,0,0,17,2,0,0,0,0,0,16,17,4,0,0,0,0,0,32,17,4,0,0,0,0,0,64,17,3,0,0,0,0,0,80,17,4,0,0,0,0,0,96,17,1,0,0,0,0,0,112,17,1,0,0,0,0,0,128,17,1,0,0,0,0,0,144,17,6,0,0,0,0,0,176,17,2,0,0,0,0,0,208,17,12,0,0,0,0,0,224,17,2,0,0,0,0,0,240,17,1,0,0,0,0,0,16,18,2,0,0,0,0,0,112,18,1,0,0,0,0,0,128,18,3,0,0,0,0,0,176,18,2,0,0,0,0,0,192,18,1,0,0,0,0,0,208,18,10,0,0,0,0,0,240,18,1,0,0,0,0,0,16,19,1,0,0,0,0,0,48,19,3,0,0,0,0,0,64,19,2,0,0,0,0,0,96,19,1,0,0,0,0,1,96,19,1,0,0,0,0,0,112,19,1,0,0,0,0,0,16,25,7,0,0,0,0,0,32,25,1,0,0,0,0,0,48,25,2,0,0,0,0,0,64,25,2,0,0,0,0,0,80,25,2,0,0,0,0,0,96,25,31,0,0,0,0,1,96,25,30,0,0,0,0,0,112,25,7,0,0,0,0,0,160,25,6,0,0,0,0,0,192,25,5,0,0,0,0,0,208,25,1,0,0,0,0,0,64,50,1,0,0,0,0,0,80,50,1,0,0,0,0,0,112,50,3,0,0,0,0,0,160,50,8,0,0,0,0,0,192,50,1,0,0,0,0,0,224,50,5,0,0,0,0,0,0,51,2,0,0,0,0,1,0,51,3,0,0,0,0,0,32,51,1,0,0,0,0,2,32,51,1,0,0,0,0,0,48,51,3,0,0,0,0,0,64,51,1,0,0,0,0,1,64,51,1,0,0,0,0,0,128,51,4,0,0,0,0,0,176,51,2,0,0,0,0,0,208,51,2,0,0,0,0,0,16,52,1,0,0,0,0,0,32,52,2,0,0,0,0,1,32,52,3,0,0,0,0,0,64,52,1,0,0,0,0,0,96,52,2,0,0,0,0,0,48,53,1,0,0,0,0,0,64,53,1,0,0,0,0,0,80,53,2,0,0,0,0,0,176,53,3,0,0,0,0,0,240,53,3,0,0,0,0,0,48,54,12,0,0,0,0,0,64,54,16,0,0,0,0,0,80,54,1,0,0,0,0,0,208,54,1,0,0,0,0,0,224,54,1,0,0,0,0,0,240,54,4,0,0,0,0,0,16,55,26,0,0,0,0,1,16,55,1,0,0,0,0,0,48,55,2,0,0,0,0,0,64,55,10,0,0,0,0,0,128,55,3,0,0,0,0,0,64,56,2,0,0,0,0,0,80,56,1,0,0,0,0,0,96,56,1,0,0,0,0,0,144,56,6,0,0,0,0,0,160,56,1,0,0,0,0,0,192,56,2,0,0,0,0,0,0,57,1,0,0,0,0,0,48,57,1,0,0,0,0,0,64,57,6,0,0,0,0,0,80,57,2,0,0,0,1,0,0,0,232,6,0,0,0,0,160,0,72,2,0,0,0,1,160,0,67,1,0,0,0,2,160,0,236,0,0,0,0,3,160,0,169,0,0,0,0,0,176,0,219,3,0,0,0,1,176,0,183,1,0,0,0,0,192,0,0,2,0,0,0,0,208,0,90,6,0,0,0,0,224,0,109,3,0,0,0,1,224,0,191,0,0,0,0,0,240,0,35,2,0,0,0,1,240,0,53,1,0,0,0,2,240,0,128,0,0,0,0,3,240,0,46,0,0,0,0,0,0,1,132,0,0,0,0,1,0,1,91,0,0,0,0,2,0,1,107,0,0,0,0,0,32,1,119,17,0,0,0,0,48,1,171,2,0,0,0,1,48,1,195,2,0,0,0,2,48,1,99,0,0,0,0,0,64,1,128,0,0,0,0,0,80,1,9,2,0,0,0,0,96,1,49,1,0,0,0,1,96,1,50,0,0,0,0,2,96,1,43,0,0,0,0,0,112,1,63,6,0,0,0,1,112,1,23,1,0,0,0,2,112,1,115,0,0,0,0,3,112,1,11,0,0,0,0,0,128,1,85,2,0,0,0,1,128,1,247,0,0,0,0,2,128,1,80,0,0,0,0,3,128,1,205,0,0,0,0,0,144,1,41,3,0,0,0,1,144,1,30,1,0,0,0,2,144,1,118,0,0,0,0,3,144,1,55,0,0,0,0,4,144,1,18,0,0,0,0,5,144,1,34,0,0,0,0,0,160,1,187,3,0,0,0,1,160,1,28,2,0,0,0,2,160,1,130,0,0,0,0,0,176,1,71,2,0,0,0,1,176,1,154,0,0,0,0,3,176,1,33,0,0,0,0,0,192,1,11,1,0,0,0,1,192,1,42,0,0,0,0,2,192,1,93,0,0,0,0,0,208,1,243,1,0,0,0,1,208,1,114,1,0,0,0,2,208,1,114,0,0,0,0,0,224,1,242,1,0,0,0,1,224,1,39,0,0,0,0,2,224,1,67,1,0,0,0,0,240,1,36,1,0,0,0,0,0,2,140,2,0,0,0,0,32,2,89,1,0,0,0,1,32,2,94,0,0,0,0,0,48,2,120,3,0,0,0,2,48,2,56,2,0,0,0,0,64,2,18,0,0,0,0,0,96,2,202,1,0,0,0,1,96,2,3,1,0,0,0,2,96,2,7,0,0,0,0,3,96,2,141,0,0,0,0,0,112,2,160,1,0,0,0,1,112,2,114,0,0,0,0,2,112,2,189,0,0,0,0,3,112,2,82,0,0,0,0,0,128,2,18,2,0,0,0,1,128,2,69,0,0,0,0,2,128,2,48,0,0,0,0,0,144,2,232,1,0,0,0,1,144,2,113,0,0,0,0,2,144,2,35,0,0,0,0,3,144,2,48,0,0,0,0,0,160,2,203,1,0,0,0,1,160,2,56,0,0,0,0,2,160,2,174,0,0,0,0,0,176,2,71,0,0,0,0,1,176,2,17,0,0,0,0,0,192,2,131,0,0,0,0,1,192,2,144,0,0,0,0,0,208,2,68,1,0,0,0,0,224,2,66,0,0,0,0,1,224,2,44,0,0,0,0,2,224,2,14,0,0,0,0,0,240,2,60,0,0,0,0,1,240,2,31,0,0,0,0,0,0,3,72,0,0,0,0,1,0,3,57,0,0,0,0,0,16,3,45,0,0,0,0,1,16,3,21,0,0,0,0,0,32,3,181,0,0,0,0,1,32,3,93,0,0,0,0,0,48,3,47,0,0,0,0,1,48,3,25,0,0,0,0,0,64,3,44,0,0,0,0,1,64,3,21,0,0,0,0,0,80,3,33,0,0,0,0,1,80,3,23,0,0,0,0,0,96,3,79,0,0,0,0,0,112,3,219,0,0,0,0,1,112,3,23,1,0,0,0,2,112,3,129,0,0,0,0,0,128,3,117,1,0,0,0,0,144,3,107,0,0,0,0,1,144,3,63,0,0,0,0,2,144,3,3,0,0,0,0,0,160,3,161,2,0,0,0,1,160,3,150,0,0,0,0,0,176,3,174,0,0,0,0,0,192,3,124,1,0,0,0,1,192,3,75,0,0,0,0,2,192,3,28,0,0,0,0,0,208,3,172,2,0,0,0,1,208,3,83,0,0,0,0,2,208,3,194,0,0,0,0,3,208,3,142,0,0,0,0,4,208,3,14,0,0,0,0,5,208,3,2,1,0,0,0,0,224,3,192,1,0,0,0,1,224,3,20,1,0,0,0,2,224,3,73,1,0,0,0,3,224,3,42,0,0,0,0,0,240,3,55,0,0,0,0,0,0,4,45,0,0,0,0,0,16,4,38,0,0,0,0,1,16,4,127,0,0,0,0,0,32,4,35,0,0,0,0,0,48,4,89,0,0,0,0,1,48,4,52,0,0,0,0,0,64,4,36,0,0,0,0,1,64,4,55,0,0,0,0,0,80,4,63,0,0,0,0,1,80,4,58,0,0,0,0,0,112,4,63,0,0,0,0,1,112,4,27,0,0,0,0,0,160,4,13,0,0,0,0,0,208,4,168,1,0,0,0,0,224,4,23,0,0,0,0,1,224,4,56,0,0,0,0,10,224,4,80,0,0,0,0,0,240,4,52,0,0,0,0,1,240,4,19,0,0,0,0,2,240,4,42,0,0,0,0,10,240,4,52,0,0,0,0,11,240,4,19,0,0,0,0,12,240,4,43,0,0,0,0,0,0,5,220,0,0,0,0,0,16,5,226,0,0,0,0,1,16,5,42,0,0,0,0,0,32,5,37,0,0,0,0,0,48,5,93,0,0,0,0,0,64,5,30,0,0,0,0,0,80,5,12,16,0,0,0,0,96,5,243,3,0,0,0,0,112,5,204,0,0,0,0,1,112,5,24,0,0,0,0,0,128,5,166,0,0,0,0,1,128,5,88,0,0,0,0,2,128,5,45,0,0,0,0,0,144,5,141,1,0,0,0,0,160,5,156,0,0,0,0,0,176,5,52,0,0,0,0,0,192,5,64,1,0,0,0,1,192,5,22,0,0,0,0,0,208,5,253,0,0,0,0,1,208,5,10,0,0,0,0,0,224,5,175,1,0,0,0,0,0,6,43,3,0,0,0,0,16,6,34,0,0,0,0,0,32,6,36,0,0,0,0,0,48,6,93,0,0,0,0,0,64,6,62,0,0,0,0,1,64,6,46,0,0,0,0,0,80,6,68,0,0,0,0,1,80,6,9,0,0,0,0,0,96,6,28,0,0,0,0,1,96,6,19,0,0,0,0,0,144,12,6,0,0,0,0,0,160,12,112,1,0,0,0,10,160,12,182,0,0,0,0,0,176,12,36,0,0,0,0,0,192,12,113,0,0,0,0,0,208,12,115,0,0,0,0,0,224,12,18,0,0,0,0,1,224,12,32,0,0,0,0,0,240,12,43,0,0,0,0,1,240,12,71,0,0,0,0,0,0,13,174,1,0,0,0,1,0,13,204,1,0,0,0,2,0,13,101,0,0,0,0,0,16,13,165,0,0,0,0,0,32,13,12,1,0,0,0,0,48,13,183,0,0,0,0,0,64,13,27,2,0,0,0,1,64,13,190,0,0,0,0,2,64,13,23,0,0,0,0,3,64,13,4,0,0,0,0,0,80,13,111,0,0,0,0,0,96,13,109,0,0,0,0,0,112,13,107,0,0,0,0,0,128,13,34,2,0,0,0,0,144,13,85,10,0,0,0,1,144,13,171,0,0,0,0,2,144,13,0,3,0,0,0,0,160,13,212,1,0,0,0,0,176,13,1,1,0,0,0,0,192,13,48,2,0,0,0,1,192,13,95,0,0,0,0,0,208,13,57,0,0,0,0,0,224,13,87,1,0,0,0,0,240,13,118,0,0,0,0,0,0,14,60,0,0,0,0,0,16,14,62,0,0,0,0,0,32,14,106,0,0,0,0,1,32,14,157,0,0,0,0,2,32,14,143,0,0,0,0,0,48,14,50,3,0,0,0,1,48,14,15,0,0,0,0,0,64,14,208,0,0,0,0,0,80,14,91,1,0,0,0,1,80,14,37,0,0,0,0,0,96,14,41,0,0,0,0,0,112,14,24,2,0,0,0,1,112,14,49,0,0,0,0,0,160,14,134,1,0,0,0,0,176,14,154,0,0,0,0,0,192,14,199,0,0,0,0,0,208,14,144,0,0,0,0,1,208,14,112,0,0,0,0,2,208,14,42,0,0,0,0,0,224,14,101,0,0,0,0,0,240,14,143,1,0,0,0,0,0,15,103,1,0,0,0,1,0,15,31,0,0,0,0,0,16,15,163,0,0,0,0,0,32,15,140,0,0,0,0,0,48,15,208,0,0,0,0,0,64,15,180,2,0,0,0,1,64,15,60,0,0,0,0,0,96,15,87,0,0,0,0,0,112,15,91,0,0,0,0,0,128,15,86,0,0,0,0,0,144,15,126,0,0,0,0,0,160,15,96,0,0,0,0,0,176,15,94,0,0,0,0,0,192,15,107,1,0,0,0,0,208,15,51,0,0,0,0,0,224,15,7,1,0,0,0,0,240,15,184,0,0,0,0,0,0,16,247,1,0,0,0,0,16,16,136,0,0,0,0,1,16,16,24,0,0,0,0,0,32,16,163,0,0,0,0,0,48,16,148,0,0,0,0,0,64,16,34,0,0,0,0,10,64,16,157,1,0,0,0,0,80,16,79,0,0,0,0,1,80,16,35,0,0,0,0,0,96,16,31,0,0,0,0,0,112,16,47,0,0,0,0,0,128,16,42,0,0,0,0,0,144,16,57,0,0,0,0,0,160,16,8,0,0,0,0,0,176,16,41,0,0,0,0,0,192,16,19,0,0,0,0,0,208,16,78,0,0,0,0,1,208,16,12,0,0,0,0,0,224,16,13,0,0,0,0,0,240,16,51,0,0,0,0,1,240,16,3,0,0,0,0,0,0,17,20,0,0,0,0,1,0,17,3,0,0,0,0,0,16,17,19,0,0,0,0,0,32,17,3,0,0,0,0,0,48,17,3,0,0,0,0,0,64,17,77,0,0,0,0,0,80,17,168,0,0,0,0,0,96,17,64,0,0,0,0,0,112,17,164,0,0,0,0,0,128,17,172,0,0,0,0,0,144,17,84,1,0,0,0,0,160,17,122,0,0,0,0,0,176,17,113,0,0,0,0,0,192,17,242,0,0,0,0,0,208,17,156,0,0,0,0,0,224,17,200,0,0,0,0,0,240,17,61,0,0,0,0,0,0,18,93,0,0,0,0,0,16,18,165,0,0,0,0,0,32,18,176,0,0,0,0,0,112,18,64,0,0,0,0,0,128,18,9,2,0,0,0,0,144,18,158,0,0,0,0,0,160,18,20,0,0,0,0,0,176,18,56,1,0,0,0,0,192,18,164,0,0,0,0,0,208,18,72,0,0,0,0,0,224,18,154,0,0,0,0,0,240,18,101,0,0,0,0,0,0,19,66,0,0,0,0,0,16,19,161,0,0,0,0,0,32,19,14,0,0,0,0,1,32,19,14,0,0,0,0,0,48,19,49,0,0,0,0,0,64,19,72,0,0,0,0,0,80,19,41,0,0,0,0,0,96,19,45,0,0,0,0,1,96,19,49,0,0,0,0,0,112,19,87,0,0,0,0,0,16,25,65,0,0,0,0,0,32,25,27,0,0,0,0,0,48,25,41,0,0,0,0,0,64,25,74,0,0,0,0,0,80,25,99,0,0,0,0,0,96,25,40,0,0,0,0,1,96,25,18,0,0,0,0,0,112,25,10,0,0,0,0,0,144,25,29,0,0,0,0,0,160,25,56,0,0,0,0,0,176,25,23,0,0,0,0,0,192,25,157,0,0,0,0,0,208,25,7,0,0,0,0,0,64,50,32,0,0,0,0,0,80,50,51,0,0,0,0,0,96,50,36,0,0,0,0,0,112,50,102,0,0,0,0,0,128,50,198,1,0,0,0,0,144,50,152,0,0,0,0,0,160,50,245,0,0,0,0,0,176,50,22,0,0,0,0,0,192,50,39,0,0,0,0,0,208,50,50,0,0,0,0,0,224,50,171,0,0,0,0,0,240,50,226,0,0,0,0,0,0,51,72,0,0,0,0,1,0,51,30,0,0,0,0,0,16,51,18,0,0,0,0,1,16,51,9,0,0,0,0,0,32,51,94,0,0,0,0,1,32,51,6,0,0,0,0,2,32,51,24,0,0,0,0,0,48,51,90,0,0,0,0,0,64,51,40,0,0,0,0,1,64,51,4,0,0,0,0,0,80,51,28,0,0,0,0,0,96,51,46,0,0,0,0,0,112,51,35,0,0,0,0,0,128,51,42,0,0,0,0,1,128,51,2,0,0,0,0,0,144,51,56,0,0,0,0,0,160,51,16,0,0,0,0,0,176,51,108,0,0,0,0,0,192,51,4,0,0,0,0,0,208,51,70,0,0,0,0,0,224,51,6,0,0,0,0,0,240,51,8,0,0,0,0,20,240,51,15,0,0,0,0,1,0,52,25,0,0,0,0,0,16,52,137,0,0,0,0,0,32,52,122,0,0,0,0,1,32,52,52,0,0,0,0,2,32,52,2,0,0,0,0,0,48,52,45,0,0,0,0,0,64,52,32,0,0,0,0,0,96,52,10,0,0,0,0,0,128,52,72,0,0,0,0,0,144,52,10,0,0,0,0,1,144,52,1,0,0,0,0,0,192,52,8,0,0,0,0,0,32,53,16,0,0,0,0,1,32,53,43,0,0,0,0,2,32,53,25,0,0,0,0,0,48,53,51,0,0,0,0,0,64,53,47,0,0,0,0,0,80,53,241,1,0,0,0,0,96,53,11,0,0,0,0,0,112,53,61,0,0,0,0,0,128,53,12,0,0,0,0,0,144,53,11,0,0,0,0,0,176,53,43,0,0,0,0,0,192,53,19,0,0,0,0,0,208,53,32,0,0,0,0,0,224,53,18,0,0,0,0,0,240,53,6,0,0,0,0,0,0,54,5,0,0,0,0,0,16,54,19,0,0,0,0,0,48,54,39,0,0,0,0,0,64,54,102,2,0,0,0,0,80,54,70,0,0,0,0,0,96,54,51,0,0,0,0,0,112,54,8,0,0,0,0,0,128,54,7,0,0,0,0,0,144,54,7,0,0,0,0,0,160,54,2,0,0,0,0,0,176,54,4,0,0,0,0,0,192,54,2,0,0,0,0,1,192,54,2,0,0,0,0,0,208,54,68,0,0,0,0,0,224,54,69,0,0,0,0,0,240,54,69,0,0,0,0,0,0,55,19,0,0,0,0,0,16,55,186,1,0,0,0,1,16,55,5,0,0,0,0,0,32,55,3,0,0,0,0,0,48,55,37,0,0,0,0,0,64,55,176,7,0,0,0,0,80,55,17,0,0,0,0,1,80,55,3,0,0,0,0,0,96,55,12,0,0,0,0,1,96,55,14,0,0,0,0,0,112,55,30,0,0,0,0,0,128,55,25,0,0,0,0,0,144,55,3,0,0,0,0,0,160,55,4,0,0,0,0,0,176,55,24,0,0,0,0,1,176,55,2,0,0,0,0,0,192,55,8,0,0,0,0,0,208,55,1,0,0,0,0,0,64,56,12,0,0,0,0,0,80,56,11,0,0,0,0,0,96,56,14,0,0,0,0,0,128,56,3,0,0,0,0,0,144,56,18,0,0,0,0,0,160,56,4,0,0,0,0,0,176,56,14,0,0,0,0,0,192,56,23,0,0,0,0,0,208,56,4,0,0,0,0,0,224,56,2,0,0,0,0,0,240,56,8,0,0,0,0,0,0,57,68,0,0,0,0,0,16,57,21,0,0,0,0,0,32,57,2,0,0,0,0,0,48,57,2,0,0,0,0,0,64,57,15,0,0,0,0,0,80,57,4,0,0,0,0,0,96,57,10,0,0,0,0,0,128,57,1,0,0,0,0,0,144,57,1,0,0,0,5,109,0,0,122,223,13,224";
var res_ = parse_savefile_infos(data);
console.log(res_);
