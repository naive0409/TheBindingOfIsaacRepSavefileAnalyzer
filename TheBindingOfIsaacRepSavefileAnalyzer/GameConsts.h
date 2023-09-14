﻿#pragma once

#include "necessaryInclude.h"

/*
const vector<vector<string>> ACHIVEMENTS =
{
{"ID","name","comment","解锁条件","reward"},
{"1","抹大拉","你解锁了“抹大拉”","在一局游戏中，同时拥有七个心之容器。","抹大拉"},
{"2","该隐","你解锁了“该隐”","在一局游戏中，同时拥有55枚硬币。","该隐"},
{"3","犹大","你解锁了“犹大”","击败撒但1次。","犹大"},
{"4","子宫","你解锁了子宫！","击败妈妈1次。","第四章"},
{"5","天启骑士","你解锁了“天启骑士”","击败妈妈1次。","饥荒骑士"},
{"6","肉块","“肉块”+绷带球已出现在地下室","击败妈妈1次。","肉块"},
{"7","启示录","“启示录”已出现在地下室","击败饥荒骑士、瘟疫骑士、战争骑士或死亡骑士1次。","启示录"},
{"8","超凡升天","“超凡升天”已出现在地下室","击败妈妈的心脏3次。","超凡升天"},
{"9","钉子","“钉子”已出现在地下室","用阿撒泻勒获得Boss Rush通关标记。","钉子"},
{"10","25美分","“25美分”已出现在地下室","击败妈妈的心脏8次。","25美分"},
{"11","胎儿博士","“胎儿博士”已出现在地下室","击败妈妈的心脏9次。","胎儿博士"},
{"12","小石头","“小石头”已出现在地下室","摧毁标记石头100次。","小石头"},
{"13","萌死戳的牙","“萌死戳的牙”已出现在地下室","通过第一章1次。","萌死戳的牙"},
{"14","小胖蛆","“小胖蛆”已出现在地下室","通过第二章1次。","小胖蛆"},
{"15","洛基的角","“洛基的角”已出现在地下室","击败洛基1次。","洛基的角"},
{"16","来自未来的东西！","“来自未来的东西！”已出现在地下室","通过地下室40次。","史蒂文"},
{"17","可爱的家伙","你解锁了“可爱的家伙”","通过第二章30次。","查德"},
{"18","粘粘的家伙","“粘粘的家伙”已出现在深牢","通过深牢20次。","吉什"},
{"19","超级绷带女孩","你拼齐了超级绷带女孩！","生成1个4级的绷带妹。","超级绷带"},
{"20","圣遗物","“圣遗物”已出现在地下室","用抹大拉获得以撒通关标记。","圣遗物"},
{"21","硬币袋","“硬币袋”已出现在地下室","用该隐获得以撒通关标记。","硬币袋"},
{"22","七原罪之书","“七原罪之书”已出现在地下室","击败懒惰、色欲、愤怒、暴食、贪婪、嫉妒和傲慢各1次。","七原罪之书"},
{"23","吉什宝宝","“吉什宝宝”已出现在地下室","击败吉什1次。","吉什宝宝"},
{"24","史蒂文宝宝","“史蒂文宝宝”已出现在地下室","击败史蒂文1次。","史蒂文宝宝"},
{"25","查德宝宝","“查德宝宝”已出现在地下室","击败查德1次。","查德宝宝"},
{"26","游戏掌机","“游戏掌机”已出现在地下室","进入10个赌博房。","游戏掌机"},
{"27","光环","“光环”已出现在地下室","使用圣经击败妈妈、妈妈的心脏或它还活着。","光环"},
{"28","大爆弹先生","“大爆弹先生”已出现在地下室","摧毁标记石头10次。","大爆弹先生"},
{"29","六面骰","以撒获得了…“六面骰！”","用???获得以撒通关标记。","六面骰"},
{"30","剪刀","“剪刀”已出现在地下室","死亡100次。","剪刀"},
{"31","寄生虫","“寄生虫”已出现在地下室","在一局游戏中，拾取2个标签“死亡”的道具。","寄生虫"},
{"32","???","你解锁了“???”","击败妈妈的心脏10次。","???"},
{"33","一切都好可怕！！！","一切都好可怕！！！","击败妈妈的心脏5次。","普通模式与困难模式难度增加"},
{"34","它还活着！","“它还活着！”你未来的过去在等着你","击败妈妈的心脏11次。","它还活着"},
{"35","妈妈的美瞳","“妈妈的美瞳”已出现在地下室","在一局游戏中，拾取3个标签“妈妈”的道具。","妈妈的美瞳"},
{"36","死灵之书","“死灵之书”已出现在地下室","使用XIII-死亡4次。","死灵之书"},
{"37","地下室小子","“地下室小子”成就达成","在不受到伤害的情况下，通过第一章。",""},
{"38","探窟小子","“探窟小子”成就达成","在不受到伤害的情况下，通过第二章。",""},
{"39","黑暗小子","“黑暗小子”成就达成","在不受到伤害的情况下，通过第三章。",""},
{"40","妈宝小子","“妈宝小子”成就达成","在不受到伤害的情况下，通过第四章。",""},
{"41","黄金大神","☆“黄金大神”达成☆","击败???和羔羊各1次。",""},
{"42","夏娃","你解锁了“夏娃”","在不拾取心的情况下，连续通过两层。","夏娃"},
{"43","妈妈的菜刀","“妈妈的菜刀”已出现在地下室","用以撒获得撒但通关标记。","妈妈的菜刀"},
{"44","剃刀片","“剃刀片”已出现在地下室","用夏娃获得撒但通关标记。","剃刀片"},
{"45","守护天使","“守护天使”已出现在地下室","用抹大拉获得撒但通关标记。","守护天使"},
{"46","炸弹袋","“炸弹袋”已出现在地下室","用该隐获得撒但通关标记。","炸弹袋"},
{"47","恶魔宝宝","“恶魔宝宝”已出现在地下室","用阿撒泻勒获得羔羊通关标记。","恶魔宝宝"},
{"48","遗忘药","“遗忘药”已出现在地下室","用???获得撒但通关标记。","遗忘药"},
{"49","二十面骰！","“二十面骰！”已出现在地下室","用以撒获得???通关标记。","二十面骰"},
{"50","凯尔特十字","“凯尔特十字”已出现在地下室","用抹大拉获得???通关标记。","凯尔特十字"},
{"51","亚伯","“亚伯”已出现在地下室","用该隐获得羔羊通关标记。","亚伯"},
{"52","弯羊角","“弯羊角”已出现在地下室","用犹大获得羔羊通关标记。","弯羊角"},
{"53","献祭匕首","“献祭匕首”已出现在地下室","用夏娃获得???通关标记。","献祭匕首"},
{"54","嗜血","“嗜血”已出现在地下室","用参孙获得以撒通关标记。","嗜血"},
{"55","染血硬币","“染血硬币”已出现在地下室","用参孙获得???通关标记。","染血硬币"},
{"56","血之权利","“血之权利”已出现在地下室","用参孙获得撒但通关标记。","血之权利"},
{"57","全家福","“全家福”已出现在地下室","击败以撒5次。","全家福"},
{"58","爸爸的钥匙","“爸爸的钥匙”已出现在地下室","在一局游戏中，同时拥有钥匙碎片1和钥匙碎片2。","爸爸的钥匙"},
{"59","蓝蜡烛","“蓝蜡烛”已出现在地下室","捐献900枚硬币给捐款机。","蓝蜡烛"},
{"60","焦灼硬币","“焦灼硬币”已出现在地下室","通过挑战#13：豆子！。","焦灼硬币"},
{"61","幸运脚趾！","“幸运脚趾！”已出现在地下室","消灭商店店主20次。","幸运脚趾"},
{"62","史诗胎儿博士","“史诗胎儿博士”已出现在地下室","通过挑战#19：顾家男人。","史诗胎儿博士"},
{"63","超级食肉男孩死忠粉","“超级食肉男孩死忠粉”已出现在地下室","通过挑战#14：尽在卡牌中。","超级食肉男孩死忠粉"},
{"64","假币","“假币”已出现在地下室","在赌博乞丐处赌博100次。","假币"},
{"65","嗝屁猫的毛球","“嗝屁猫的毛球”已出现在地下室","在一局游戏中，拾取3个标签“嗝屁猫”的道具。","嗝屁猫的毛球"},
{"66","被遗忘的骑士","你解锁了“被遗忘的骑士”","在天使房中，拾取10个道具。","征服骑士"},
{"67","参孙","你解锁了“参孙”","在不受到伤害的情况下，连续通过两层。","参孙"},
{"68","恶心的家伙！","你解锁了“恶心的家伙！”","击败以撒10次。","三腿蜘蛛"},
{"69","白金大神！","白金大神！","解锁重生版本中除游魂及其相关成就以外的所有道具、结局和成就。",""},
{"70","以撒的头","“以撒的头”已出现在地下室","用以撒获得Boss Rush通关标记。","以撒的头"},
{"71","抹大拉的信仰","“抹大拉的信仰”已出现在地下室","用抹大拉获得羔羊通关标记。","抹大拉的信仰"},
{"72","犹大的舌头","“犹大的舌头”已出现在地下室","用犹大获得撒但通关标记。","犹大的舌头"},
{"73","???的灵魂","“???的灵魂”已出现在地下室","用???获得羔羊通关标记。","???的灵魂"},
{"74","参孙的发髻","“参孙的发髻”已出现在地下室","用参孙获得羔羊通关标记。","参孙的发髻"},
{"75","该隐的眼睛","“该隐的眼睛”已出现在地下室","用该隐获得???通关标记。","该隐的眼睛"},
{"76","夏娃的鸟爪","“夏娃的鸟爪”已出现在地下室","用夏娃获得以撒通关标记。","夏娃的鸟爪"},
{"77","左断手","“左断手”已出现在地下室","用犹大获得???通关标记。","左断手"},
{"78","底片","“底片”已出现在地下室","击败撒但5次。","底片"},
{"79","阿撒泻勒","你解锁了“阿撒泻勒”","在一局游戏中，进行3次恶魔交易。","阿撒泻勒"},
{"80","拉撒路","你解锁了“拉撒路”","在一局游戏中，拥有四颗魂心。","拉撒路"},
{"81","伊甸","你解锁了“伊甸”","击败妈妈的心脏1次。","伊甸"},
{"82","游魂","你解锁了“游魂”","角色因献祭而死亡，且拥有寻人启事。","游魂"},
{"83","死亡小子","“死亡小子”成就达成","在不受到伤害的情况下，通过第六章。",""},
{"84","真·白金大神！","真·白金大神！","收集所有道具并解锁所有结局。",""},
{"85","幸运石","“幸运石”已出现在地下室","摧毁100个石头。","幸运石"},
{"86","地窖","你解锁了地窖！","击败地下室中的所有头目各1次。","地窖"},
{"87","墓穴","你解锁了墓穴！","击败洞穴中的所有头目各1次。","墓穴"},
{"88","坟场","你解锁了坟场！","击败深牢中的所有头目各1次。","坟场"},
{"89","冰雹符文","“冰雹符文”已出现在地下室","通过挑战#1：漆黑一片。","冰雹符文"},
{"90","收获符文","“收获符文”已出现在地下室","通过挑战#2：格调高雅。","收获符文"},
{"91","马骑符文","“马骑符文”已出现在地下室","通过挑战#3：头部创伤。","马骑符文"},
{"92","朝夕符文","“朝夕符文”已出现在地下室","通过挑战#4：黑暗降临。","朝夕符文"},
{"93","诸神符文","“诸神符文”已出现在地下室","通过挑战#5：坦克。","诸神符文"},
{"94","签筒符文","“签筒符文”已出现在地下室","通过挑战#6：太阳系。","签筒符文"},
{"95","桦木符文","“桦木符文”已出现在地下室","通过挑战#20：返璞归真。","桦木符文"},
{"96","保护符文","“保护符文”已出现在地下室","通过挑战#8：好奇害死猫。","保护符文"},
{"97","混沌卡","“混沌卡”已出现在地下室","通过挑战#9：拆迁办。","混沌卡"},
{"98","信用卡","“信用卡”已出现在地下室","通过挑战#10：诅咒！。","信用卡"},
{"99","规则卡","“规则卡”已出现在地下室","通过挑战#11：玻璃大炮。","规则卡"},
{"100","反人类卡","“反人类卡”已出现在地下室","通过挑战#12：当生活充满酸意。","反人类卡"},
{"101","被吞下的硬币","“被吞下的硬币”已出现在地下室","通过挑战#15：慢吞吞。","被吞下的硬币"},
{"102","机器宝宝2.0！","“机器宝宝2.0！”已出现在地下室","通过挑战#16：技术宅。","机器宝宝2.0"},
{"103","死神之触","“死神之触”已出现在地下室","通过挑战#17：吐豆人。","死神之触"},
{"104","科技0.5","“科技0.5”已出现在地下室","通过挑战#18：宿主。","科技0.5"},
{"105","编号丢失","“编号丢失”已出现在地下室","用拉撒路获得Boss Rush通关标记。","编号丢失"},
{"106","以撒的泪盆","“以撒的泪盆”已出现在地下室","用以撒获得以撒通关标记。","以撒的泪盆"},
{"107","断头台","“断头台”已出现在地下室","用犹大获得以撒通关标记。","断头台"},
{"108","犹大的影子","“犹大的影子”已出现在地下室","用犹大获得Boss Rush通关标记。","犹大的影子"},
{"109","抹大拉的蝴蝶结","“抹大拉的蝴蝶结”已出现在地下室","用抹大拉获得Boss Rush通关标记。","抹大拉的蝴蝶结"},
{"110","该隐的另一只眼","“该隐的另一只眼”已出现在地下室","用该隐获得Boss Rush通关标记。","该隐的另一只眼"},
{"111","黑色口红","“黑色口红”已出现在地下室","用夏娃获得羔羊通关标记。","黑色口红"},
{"112","夏娃的睫毛膏","“夏娃的睫毛膏”已出现在地下室","用夏娃获得Boss Rush通关标记。","夏娃的睫毛膏"},
{"113","宿命","“宿命”已出现在地下室","用???获得???通关标记。","宿命"},
{"114","???唯一的朋友","“???的唯一的∨朋友”已出现在地下室","用???获得Boss Rush通关标记。","???唯一的朋友"},
{"115","参孙的脚镣","“参孙的脚镣”已出现在地下室","用参孙获得Boss Rush通关标记。","参孙的脚镣"},
{"116","拉撒路的绷带","“拉撒路的绷带”已出现在地下室","用拉撒路获得以撒通关标记。","拉撒路的绷带"},
{"117","碎安卡十字","“碎安卡十字”已出现在地下室","用拉撒路获得撒但通关标记。","碎安卡十字"},
{"118","商店积分","“商店积分”已出现在地下室","用拉撒路获得???通关标记。","商店积分"},
{"119","潘多拉魔盒","“潘多拉魔盒”已出现在地下室","用拉撒路获得羔羊通关标记。","潘多拉魔盒"},
{"120","自杀之王","“自杀之王”已出现在地下室","通过挑战#7：自杀之王。","自杀之王"},
{"121","空白卡牌","“空白卡牌”已出现在地下室","用伊甸获得以撒通关标记。","空白卡牌"},
{"122","秘密之书","“秘密之书”已出现在地下室","用伊甸获得撒但通关标记。","秘密之书"},
{"123","神秘纸片","“神秘纸片”已出现在地下室","用伊甸获得???通关标记。","神秘纸片"},
{"124","神秘的袋子","“神秘的袋子”已出现在地下室","用伊甸获得羔羊通关标记。","神秘的袋子"},
{"125","未定义","“未定义”已出现在地下室","用伊甸获得Boss Rush通关标记。","未定义"},
{"126","撒但圣经","“撒但圣经”已出现在地下室","用阿撒泻勒获得以撒通关标记。","撒但圣经"},
{"127","恶魔的尾巴","“恶魔的尾巴”已出现在地下室","用阿撒泻勒获得撒但通关标记。","恶魔的尾巴"},
{"128","亚巴顿","“亚巴顿”已出现在地下室","用阿撒泻勒获得???通关标记。","亚巴顿"},
{"129","以撒的心脏","“以撒的心脏”已出现在地下室","用游魂获得以撒通关标记。","以撒的心脏"},
{"130","思想","“思想”已出现在地下室","用游魂获得撒但通关标记。","思想"},
{"131","肉体","“肉体”已出现在地下室","用游魂获得???通关标记。","肉体"},
{"132","灵魂","“灵魂”已出现在地下室","用游魂获得羔羊通关标记。","灵魂"},
{"133","一百面骰！","“一百面骰！”已出现在地下室","用游魂获得Boss Rush通关标记。","一百面骰"},
{"134","蓝地图","“蓝地图”已出现在地下室","捐献10枚硬币给捐款机。","蓝地图"},
{"135","额外选择","“额外选择”已出现在地下室","捐献50枚硬币给捐款机。","额外选择"},
{"136","黑蜡烛","“黑蜡烛”已出现在地下室","捐献150枚硬币给捐款机。","黑蜡烛"},
{"137","红蜡烛","“红蜡烛”已出现在地下室","捐献400枚硬币给捐款机。","红蜡烛"},
{"138","怀表","“怀表”已出现在地下室","捐献999枚硬币给捐款机。","怀表"},
{"139","铁丝衣架","“铁丝衣架”已出现在地下室","击败妈妈的心脏4次。","铁丝衣架"},
{"140","吐根酊","“吐根酊”已出现在地下室","击败妈妈的心脏6次。","吐根酊"},
{"141","实验性疗法","“实验性疗法”已出现在地下室","击败妈妈的心脏7次。","实验性疗法"},
{"142","坎卜斯","你解锁了“坎卜斯”","在恶魔房中，拾取20个道具。","坎卜斯"},
{"143","坎卜斯的头","“坎卜斯的头”已出现在地下室","击败坎卜斯1次。","坎卜斯的头"},
{"144","超级食肉男孩！","你拼齐了超级食肉男孩！","生成1个4级的肉块。",""},
{"145","棉豆","“棉豆”已出现在地下室","摧毁100个大便 (障碍物)。","棉豆"},
{"146","小药袋","“小药袋”已出现在地下室","在一局游戏中，拾取2个标签“注射器”的道具。","小药袋"},
{"147","血袋","“血袋”已出现在地下室","使用献血机30次。","血袋"},
{"148","四面骰！","“四面骰！”已出现在地下室","摧毁赌博机30次。","四面骰"},
{"149","寻人启事","“寻人启事”已出现在地下室","用以撒获得羔羊通关标记。","寻人启事"},
{"150","橡胶胶水","“橡胶胶水”已出现在地下室","击败妈妈的心脏2次。","橡胶胶水"},
{"151","商店升级","“商店升级”1级","捐献20枚硬币给捐款机。","商店将会出售3个物品"},
{"152","商店升级","“商店升级”2级","捐献100枚硬币给捐款机。","商店将会出售4个物品"},
{"153","商店升级","“商店升级”3级","捐献200枚硬币给捐款机。","商店将会出售5个物品"},
{"154","商店升级","“商店升级”4级","捐献600枚硬币给捐款机。","商店将会出售6个物品"},
{"155","天使","天使在等待！！！","击败???或羔羊1次。","乌列"},
{"156","神性","“神性”已出现在地下室","用游魂获得所有困难模式通关标记。","神性"},
{"157","黑暗降临","你解锁了挑战#4黑暗降临","用夏娃获得???与撒但通关标记。","挑战#4：黑暗降临"},
{"158","坦克","你解锁了挑战#5坦克","解锁抹大拉。","挑战#5：坦克"},
{"159","太阳系","你解锁了挑战#6太阳系","解锁超凡升天。","挑战#6：太阳系"},
{"160","自杀之王","你解锁了挑战#7自杀之王","解锁它还活着。","挑战#7：自杀之王"},
{"161","好奇害死猫","你解锁了挑战#8好奇害死猫","解锁嗝屁猫的毛球。","挑战#8：好奇害死猫"},
{"162","拆迁办","你解锁了挑战#9拆迁办","解锁胎儿博士。","挑战#9：拆迁办"},
{"163","诅咒！","你解锁了挑战#10诅咒！","解锁抹大拉。","挑战#10：诅咒！"},
{"164","玻璃大炮","你解锁了挑战#11玻璃大炮","解锁史诗胎儿博士和洛基的角。","挑战#11：玻璃大炮"},
{"165","顾家男人","你解锁了挑战#19顾家男人","解锁爸爸的钥匙和它还活着。","挑战#19：顾家男人"},
{"166","返璞归真","你解锁了挑战#20返璞归真","解锁第四章。","挑战#20：返璞归真"},
{"167","遗失宝宝","你解锁了遗失宝宝","用以撒获得困难模式妈妈的心脏通关标记。","遗失宝宝"},
{"168","可爱宝宝","你解锁了可爱宝宝","用抹大拉获得困难模式妈妈的心脏通关标记。","可爱宝宝"},
{"169","乌鸦宝宝","你解锁了乌鸦宝宝","用夏娃获得困难模式妈妈的心脏通关标记。","乌鸦宝宝"},
{"170","暗影宝宝","你解锁了暗影宝宝","用犹大获得困难模式妈妈的心脏通关标记。","暗影宝宝"},
{"171","玻璃宝宝","你解锁了玻璃宝宝","用该隐获得困难模式妈妈的心脏通关标记。","玻璃宝宝"},
{"172","绷带宝宝","你解锁了绷带宝宝","用拉撒路获得困难模式妈妈的心脏通关标记。","绷带宝宝"},
{"173","受生魔宝宝","你解锁了受生魔宝宝","用阿撒泻勒获得困难模式妈妈的心脏通关标记。","受生魔宝宝"},
{"174","死尸宝宝","你解锁了死尸宝宝","用???获得困难模式妈妈的心脏通关标记。","死尸宝宝"},
{"175","O","你解锁了“O”","用游魂获得困难模式妈妈的心脏通关标记。","O"},
{"176","故障宝宝","你解锁了故障宝宝","用伊甸获得困难模式妈妈的心脏通关标记。","故障宝宝"},
{"177","格斗宝宝","你解锁了格斗宝宝","用参孙获得困难模式妈妈的心脏通关标记。","格斗宝宝"},
{"178","苍蝇领主！","你变成了...苍蝇领主！","在一局游戏中，拾取3个标签“苍蝇”的道具。",""},
{"179","放屁宝宝","“放屁宝宝”已出现在地下室","用以撒获得死寂通关标记。","放屁宝宝"},
{"180","纯洁","“纯洁”已出现在地下室","用抹大拉获得死寂通关标记。","纯洁"},
{"181","十二面骰","“十二面骰”已出现在地下室","用该隐获得死寂通关标记。","十二面骰"},
{"182","背叛","“背叛”已出现在地下室","用犹大获得死寂通关标记。","背叛"},
{"183","宿命的报答","“宿命的报答”已出现在地下室","用???获得死寂通关标记。","宿命的报答"},
{"184","祭祀之刃","“祭祀之刃”已出现在地下室","用夏娃获得死寂通关标记。","祭祀之刃"},
{"185","盲目的怒火","“盲目的怒火”已出现在地下室","用参孙获得死寂通关标记。","盲目的怒火"},
{"186","虚空之喉","“虚空之喉”已出现在地下室","用阿撒泻勒获得死寂通关标记。","虚空之喉"},
{"187","空容器","“空容器”已出现在地下室","用拉撒路获得死寂通关标记。","空容器"},
{"188","伊甸的祝福","“伊甸的祝福”已出现在地下室","用伊甸获得死寂通关标记。","伊甸的祝福"},
{"189","宣誓守护者","“宣誓守护者”已出现在地下室","用游魂获得死寂通关标记。","宣誓守护者"},
{"190","淫魔","“淫魔”已出现在地下室","用莉莉丝获得死寂通关标记。","淫魔"},
{"191","一枚硬币！","店主获得了…“一枚硬币！”","用店主获得死寂通关标记。","店主初始携带1枚硬币"},
{"192","小箱子","“小箱子”已出现在地下室","用以撒获得贪婪模式通关标记。","小箱子"},
{"193","香炉","“香炉”已出现在地下室","用抹大拉获得贪婪模式通关标记。","香炉"},
{"194","邪恶之眼","“邪恶之眼”已出现在地下室","用该隐获得贪婪模式通关标记。","邪恶之眼"},
{"195","我的影子","“我的影子”已出现在地下室","用犹大获得贪婪模式通关标记。","我的影子"},
{"196","碎裂六面骰","“碎裂六面骰”已出现在地下室","用???获得贪婪模式通关标记。","碎裂六面骰"},
{"197","黑色羽毛","“黑色羽毛”已出现在地下室","用夏娃获得贪婪模式通关标记。","黑色羽毛"},
{"198","血嗜","“血嗜”已出现在地下室","用参孙获得贪婪模式通关标记。","血嗜"},
{"199","莉莉丝","你解锁了“莉莉丝”","用阿撒泻勒获得贪婪模式通关标记。","莉莉丝"},
{"200","钥匙乞丐","“钥匙乞丐”已出现在地下室","用拉撒路获得贪婪模式通关标记。","钥匙乞丐"},
{"201","恶性漏洞","“恶性漏洞”已出现在地下室","用伊甸获得贪婪模式通关标记。","恶性漏洞"},
{"202","黄道十二宫","“黄道十二宫”已出现在地下室","用游魂获得贪婪模式通关标记。","黄道十二宫"},
{"203","朋友盒","“朋友盒”已出现在地下室","用莉莉丝获得贪婪模式通关标记。","朋友盒"},
{"204","贪婪的肋骨","“贪婪的肋骨”已出现在地下室","用店主获得贪婪模式通关标记。","贪婪的肋骨"},
{"205","爱哭宝宝","“爱哭宝宝”已出现在地下室","用以撒获得超级撒但通关标记。","爱哭宝宝"},
{"206","红宝宝","“红宝宝”已出现在地下室","用抹大拉获得超级撒但通关标记。","红宝宝"},
{"207","绿宝宝","“绿宝宝”已出现在地下室","用该隐获得超级撒但通关标记。","绿宝宝"},
{"208","棕宝宝","“棕宝宝”已出现在地下室","用犹大获得超级撒但通关标记。","棕宝宝"},
{"209","蓝宝宝","“蓝宝宝”已出现在地下室","用???获得超级撒但通关标记。","蓝宝宝"},
{"210","小宝宝","“小宝宝”已出现在地下室","用夏娃获得超级撒但通关标记。","小宝宝"},
{"211","愤怒宝宝","“愤怒宝宝”已出现在地下室","用参孙获得超级撒但通关标记。","愤怒宝宝"},
{"212","黑宝宝","“黑宝宝”已出现在地下室","用阿撒泻勒获得超级撒但通关标记。","黑宝宝"},
{"213","长宝宝","“长宝宝”已出现在地下室","用拉撒路获得超级撒但通关标记。","长宝宝"},
{"214","黄宝宝","“黄宝宝”已出现在地下室","用伊甸获得超级撒但通关标记。","黄宝宝"},
{"215","白宝宝","“白宝宝”已出现在地下室","用游魂获得超级撒但通关标记。","白宝宝"},
{"216","大宝宝","“大宝宝”已出现在地下室","用莉莉丝获得超级撒但通关标记。","大宝宝"},
{"217","上吊绳宝宝","“上吊绳宝宝”已出现在地下室","用店主获得超级撒但通关标记。","上吊绳宝宝"},
{"218","符文袋","“符文袋”已出现在地下室","用莉莉丝获得以撒通关标记。","符文袋"},
{"219","恶魔受胎","“恶魔受胎”已出现在地下室","用莉莉丝获得???通关标记。","恶魔受胎"},
{"220","蛇蝎之吻","“蛇蝎之吻”已出现在地下室","用莉莉丝获得撒但通关标记。","蛇蝎之吻"},
{"221","魅魔","“魅魔”已出现在地下室","用莉莉丝获得羔羊通关标记。","魅魔"},
{"222","圣灵受胎","“圣灵受胎”已出现在地下室","用莉莉丝获得Boss Rush通关标记。","圣灵受胎"},
{"223","羊头宝宝","“羊头宝宝”已出现在地下室","用莉莉丝获得困难模式妈妈的心脏通关标记。","羊头宝宝"},
{"224","金心","“金心”已出现在地下室","通过挑战#21：超超超超超大层。","金心"},
{"225","免费保释卡","免费保释卡已出现在地下室","通过挑战#22：快马加鞭！。","免费保释卡"},
{"226","金炸弹","“金炸弹”已出现在地下室","通过挑战#23：蓝色炸弹人。","金炸弹"},
{"227","2枚新胶囊","2枚新胶囊出现了！！","通过挑战#24：充钱游戏。","止痛药！"},
{"228","2枚新胶囊","2枚新胶囊出现了！！","通过挑战#25：没心没肺。","放-松"},
{"229","筹码","“筹码”已出现在地下室","通过挑战#26：以撒传说！。","筹码"},
{"230","饰钉定位器","“饰钉定位器”已出现在地下室","通过挑战#27：脑子！。","饰钉定位器"},
{"231","八面骰","“八面骰”已出现在地下室","通过挑战#28：彩虹日！。","八面骰"},
{"232","肾结石","“肾结石”已出现在地下室","通过挑战#29：俄南连击。","肾结石"},
{"233","空白符文","“空白符文”已出现在地下室","通过挑战#30：守护者。","空白符文"},
{"234","蓝子宫！","你解锁了蓝子宫！","击败妈妈的心脏10次。","???"},
{"235","1001%！！","1001%！！","收集图鉴中的所有道具并解锁重生和胎衣版本中所有成就和结局。",""},
{"236","木制镍币","店主获得了...“木制镍币”","用店主获得以撒通关标记。","店主初始携带木制镍币"},
{"237","商店钥匙","店主获得了...“商店钥匙”","用店主获得撒但通关标记。","店主初始携带商店钥匙"},
{"238","深口袋","“深口袋”已出现在地下室","用店主获得???通关标记。","深口袋"},
{"239","业报","“业报”已出现在地下室","用店主获得羔羊通关标记。","业报"},
{"240","黏性镍币","“黏性镍币”已出现在地下室","用店主获得Boss Rush通关标记。","黏性镍币"},
{"241","超级贪婪宝宝","“超级贪婪宝宝”已出现在地下室","用店主获得困难模式妈妈的心脏通关标记。","超级贪婪宝宝"},
{"242","幸运硬币","“幸运硬币”已出现在地下室","捐献2枚硬币给贪婪机。","幸运硬币"},
{"243","特殊上吊店主！","你解锁了特殊上吊店主！","捐献14枚硬币给贪婪机。","特殊隐藏房店主"},
{"244","木制镍币","“木制镍币”已出现在地下室","捐献33枚硬币给贪婪机。","木制镍币"},
{"245","回形针","该隐获得了...“回形针”","捐献68枚硬币给贪婪机。","该隐初始携带回形针"},
{"246","一切都好可怕2！！！","一切都好可怕2！！！","捐献111枚硬币给贪婪机。","贪婪模式和困难贪婪模式难度增加"},
{"247","特殊店主！","你解锁了特殊店主！","捐献234枚硬币给贪婪机。","特殊商店店主"},
{"248","剃刀片","夏娃获得了...“剃刀片”","捐献439枚硬币给贪婪机。","夏娃初始携带剃刀片"},
{"249","商店钥匙","“商店钥匙”已出现在地下室","捐献666枚硬币给贪婪机。","商店钥匙"},
{"250","神圣屏障","游魂获得了...“神圣屏障”","捐献879枚硬币给贪婪机。","游魂初始携带神圣屏障"},
{"251","店主","你解锁了“店主”","捐献1000枚硬币给贪婪机。","店主"},
{"252","虫巢宝宝","“虫巢宝宝”已出现在地下室","用???获得所有困难通关标记","虫巢宝宝"},
{"253","无头宝宝","“无头宝宝”已出现在地下室","用以撒获得所有困难通关标记","无头宝宝"},
{"254","彩色宝宝","“彩色宝宝”已出现在地下室","用抹大拉获得所有困难通关标记","彩色宝宝"},
{"255","淫妇宝宝","“淫妇宝宝”已出现在地下室","用夏娃获得所有困难通关标记","淫妇宝宝"},
{"256","碎裂宝宝","“碎裂宝宝”已出现在地下室","用伊甸获得所有困难通关标记","碎裂宝宝"},
{"257","滴血宝宝","“滴血宝宝”已出现在地下室","用拉撒路获得所有困难通关标记","滴血宝宝"},
{"258","亮瞎宝宝","“亮瞎宝宝”已出现在地下室","使用空白卡牌触发XIX-太阳。","亮瞎宝宝"},
{"259","魅魔宝宝","“魅魔宝宝”已出现在地下室","用阿撒泻勒获得所有困难通关标记","魅魔宝宝"},
{"260","黑暗宝宝","“黑暗宝宝”已出现在地下室","用莉莉丝获得所有困难通关标记","黑暗宝宝"},
{"261","衣架宝宝","“衣架宝宝”已出现在地下室","用该隐获得所有困难通关标记","衣架宝宝"},
{"262","复仇宝宝","“复仇宝宝”已出现在地下室","用参孙获得所有困难通关标记","复仇宝宝"},
{"263","彼列宝宝","“彼列宝宝”已出现在地下室","用犹大获得所有困难通关标记","彼列宝宝"},
{"264","折扣宝宝","“折扣宝宝”已出现在地下室","用店主获得所有困难通关标记","折扣宝宝"},
{"265","超超超超超大层","你解锁了挑战#21超超超超超大层","解锁第四章。","挑战#21：超超超超超大层"},
{"266","快马加鞭！","你解锁了挑战#22快马加鞭！","解锁第四章。","挑战#22：快马加鞭！"},
{"267","蓝色炸弹人","你解锁了挑战#23蓝色炸弹人","解锁???和它还活着。","挑战#23：蓝色炸弹人"},
{"268","充钱游戏","你解锁了挑战#24充钱游戏","解锁硬币袋和它还活着。","挑战#24：充钱游戏"},
{"269","没心没肺","你解锁了挑战#25没心没肺","解锁第四章。","挑战#25：没心没肺"},
{"270","以撒传说！","你解锁了挑战#26以撒传说！","击败超级撒但1次。","挑战#26：以撒传说！"},
{"271","脑子！","你解锁了挑战#27脑子！","解锁全家福。","挑战#27：脑子！"},
{"272","彩虹日！","你解锁了挑战#28彩虹日！","解锁第四章。","挑战#28：彩虹日！"},
{"273","俄南连击","你解锁了挑战#29俄南连击","解锁犹大和它还活着。","挑战#29：俄南连击"},
{"274","守护者","你解锁了挑战#30守护者","解锁第四章。","挑战#30：守护者"},
{"275","慷慨","如果每个人都像你一样慷慨就好了…","捐献999枚硬币给贪婪机。",""},
{"276","超级喷射！","“超级喷射！”已出现在地下室","用所有非堕化人物获得超级撒但通关标记。","超级喷射"},
{"277","本末倒置","你解锁了挑战#31本末倒置","击败超级撒但1次。","挑战#31：本末倒置"},
{"278","愚人节","你解锁了挑战#32愚人节","解锁第四章。","挑战#32：愚人节"},
{"279","宝可萌","你解锁了挑战#33宝可萌","解锁它还活着。","挑战#33：宝可萌"},
{"280","终极困难","你解锁了挑战#34终极困难","击败超级撒但1次。","挑战#34：终极困难"},
{"281","乒乓","你解锁了挑战#35乒乓","解锁全家福。","挑战#35：乒乓"},
{"282","∞面骰","“无限面骰”已出现在地下室","用以撒获得精神错乱通关标记。","无限面骰"},
{"283","圣餐","“圣餐”已出现在地下室","用抹大拉获得精神错乱通关标记。","圣餐"},
{"284","银币","“银币”已出现在地下室","用该隐获得精神错乱通关标记。","银币"},
{"285","阴影","“阴影”已出现在地下室","用犹大获得精神错乱通关标记。","阴影"},
{"286","国王宝宝","“国王宝宝”已出现在地下室","用???获得精神错乱通关标记。","国王宝宝"},
{"287","染血王冠","“染血王冠”已出现在地下室","用参孙获得精神错乱通关标记。","染血王冠"},
{"288","钝剃刀片","“钝剃刀片”已出现在地下室","用夏娃获得精神错乱难通关标记。","钝剃刀片"},
{"289","伊甸的灵魂","“伊甸的灵魂”已出现在地下室","用伊甸获得精神错乱通关标记。","伊甸的灵魂"},
{"290","黑王子之冠","“黑王子之冠”已出现在地下室","用阿撒泻勒获得精神错乱通关标记。","黑王子之冠"},
{"291","复杂性骨折","“复杂性骨折”已出现在地下室","用拉撒路获得精神错乱通关标记。","复杂性骨折"},
{"292","安乐死","“安乐死”已出现在地下室","用莉莉丝获得精神错乱通关标记。","安乐死"},
{"293","神圣卡","“神圣卡”已出现在地下室","用游魂获得精神错乱通关标记。","神圣卡"},
{"294","被掰弯的硬币","“被掰弯的硬币”已出现在地下室","用店主获得精神错乱通关标记。","被掰弯的硬币"},
{"295","虚空","“虚空”已出现在地下室","用亚玻伦获得精神错乱通关标记。","虚空"},
{"296","一面骰","“一面骰”已出现在地下室","用以撒获得困难贪婪模式通关标记。","一面骰"},
{"297","平衡符号","“平衡符号”已出现在地下室","用抹大拉获得困难贪婪模式通关标记。","平衡符号"},
{"298","袋中袋","“袋中袋”已出现在地下室","用该隐获得困难贪婪模式通关标记。","袋中袋"},
{"299","彼列之眼","“彼列之眼”已出现在地下室","用犹大获得困难贪婪模式通关标记。","彼列之眼"},
{"300","胎粪","“胎粪”已出现在地下室","用???获得困难贪婪模式通关标记。","胎粪"},
{"301","干细胞","“干细胞”已出现在地下室","用参孙获得困难贪婪模式通关标记。","干细胞"},
{"302","乌鸦的心","“乌鸦的心”已出现在地下室","用夏娃获得困难贪婪模式通关标记。","乌鸦的心"},
{"303","节拍器","“节拍器”已出现在地下室","用伊甸获得困难贪婪模式通关标记。","节拍器"},
{"304","蝙蝠翅膀","“蝙蝠翅膀”已出现在地下室","用阿撒泻勒获得困难贪婪模式通关标记。","蝙蝠翅膀"},
{"305","计划C","“计划C”已出现在地下室","用拉撒路获得困难贪婪模式通关标记。","计划C"},
{"306","二元性","“二元性”已出现在地下室","用莉莉丝获得困难贪婪模式通关标记。","二元性"},
{"307","爸爸丢失的硬币","“爸爸丢失的硬币”已出现在地下室","用游魂获得困难贪婪模式通关标记。","爸爸丢失的硬币"},
{"308","贪婪的眼睛","“贪婪的眼睛”已出现在地下室","用店主获得困难贪婪模式通关标记。","贪婪的眼睛"},
{"309","黑符文","“黑符文”已出现在地下室","用亚玻伦获得困难贪婪模式通关标记。","黑符文"},
{"310","战争蝗虫","“战争蝗虫”已出现在地下室","用亚玻伦获得以撒通关标记。","战争蝗虫"},
{"311","瘟疫蝗虫","“瘟疫蝗虫”已出现在地下室","用亚玻伦获得撒但通关标记。","瘟疫蝗虫"},
{"312","饥荒蝗虫","“饥荒蝗虫”已出现在地下室","用亚玻伦获得???通关标记。","饥荒蝗虫"},
{"313","死亡蝗虫","“死亡蝗虫”已出现在地下室","用亚玻伦获得羔羊通关标记。","死亡蝗虫"},
{"314","征服蝗虫","“征服蝗虫”已出现在地下室","用亚玻伦获得Boss Rush通关标记。","征服蝗虫"},
{"315","小死寂","“小死寂”已出现在地下室","用亚玻伦获得死寂通关标记。","死寂宝宝"},
{"316","棕色粪块","“棕色粪块”已出现在地下室","用亚玻伦获得贪婪模式通关标记。","棕色粪块"},
{"317","死眼宝宝","“死眼宝宝”已出现在地下室","用亚玻伦获得超级撒但通关标记。","死眼宝宝"},
{"318","熔炉","“熔炉”已出现在地下室","用亚玻伦获得困难模式妈妈的心脏通关标记。","熔炉"},
{"319","亚玻伦宝宝","“亚玻伦宝宝”已出现在地下室","用亚玻伦获得所有困难通关标记。","亚玻伦宝宝"},
{"320","虚空","你解锁了虚空！","击败死寂1次。","虚空"},
{"321","再次心动！","1枚新胶囊出现了！！","完成跑圈1次。","咕噜！"},
{"322","帽子戏法！","“梅花A”已出现在地下室","完成3连胜1次。","梅花A"},
{"323","超级标记石头","“超级标记石头”已出现在地下室","用3个不同的人物完成3连胜1次。","超级标记石头"},
{"324","罪恶收藏家","1枚新胶囊出现了！！","探索怪物图鉴中的所有怪物。","感觉像漫步在阳光下！"},
{"325","献身","1枚新胶囊出现了！！","累计参加31天的每日挑战。","呕！"},
{"326","冲！","“方片A”已出现在地下室","在20分钟内击败羔羊。","方片A"},
{"327","这就是钥匙","“黑桃A”已出现在地下室","在不拾取心、硬币和炸弹的情况下，击败羔羊。","黑桃A"},
{"328","重开先生！","“胆小的红心”已出现在地下室","连续重新开始游戏7次（PC）/达到-10连胜（NS、PS4）。","胆小的红心"},
{"329","刀刃上生存","“红桃A”已出现在地下室","在只拥有半颗心的情况下，完成一层（第一层除外）。","红桃A"},
{"330","你弄坏了！","1枚新胶囊出现了！！","在一局游戏中，拥有50个以上的道具。","嗝！"},
{"331","拉撒路大出血！","拉撒路大出血！","通过挑战#31：本末倒置。","拉撒路初始携带贫血"},
{"332","一枚胶囊！","抹大拉获得了...“一枚胶囊”！","通过挑战#32：愚人节。","抹大拉初始携带体力回满"},
{"333","充能钥匙","“充能钥匙”已出现在地下室","通过挑战#33：宝可萌。","充能钥匙"},
{"334","参孙感觉很健康！","参孙感觉很健康！","通过挑战#34：终极困难。","参孙初始携带小孩的心脏"},
{"335","贪婪的胃袋","“贪婪的胃袋”已出现在地下室","通过挑战#35：乒乓。","贪婪的胃袋"},
{"336","碎裂的王冠","“碎裂的王冠”已出现在地下室","每日挑战完成5连胜，且分数大于0（不必连续5天）。","碎裂的王冠"},
{"337","续关","你解锁了续关！","在一局游戏中，完成跑圈3次。","续关"},
{"338","精神错乱","“精神错乱”已出现在地下室","击败精神错乱1次。","精神错乱"},
{"339","10000","10000","",""},
{"340","亚玻伦","你解锁了“亚玻伦”","击败超级撒但1次。","亚玻伦"},
{"341","更加贪婪！","你已变得更加贪婪！","捐献500枚硬币给贪婪机。","困难贪婪模式"},
{"342","燃烧！","地下室在燃烧！","击败妈妈的心脏11次。","燃烧地下室"},
{"343","水淹！","洞穴被水淹了！","击败它还活着16次。","淹水洞穴"},
{"344","阴冷！","深牢变阴湿了！","击败它还活着21次。","阴湿深牢"},
{"345","瘢痕！","子宫里结痂了！","击败它还活着30次。","结痂子宫"},
{"346","邪恶的怪物正在接近！","邪恶的怪物正在接近！","获得3个???通关标记。","脆皮虫"},
{"347","邪恶的怪物正在接近+！","邪恶的怪物正在接近+！","获得6个???通关标记。","骨堆畸胎"},
{"348","大门是开着的！","大门是开着的！","击败羔羊1次。","黑洞"},
{"349","黑洞","“黑洞”已出现在地下室","击败黑洞20次。","黑洞"},
{"350","神秘礼物","“神秘礼物”已出现在地下室","摧毁500个石头。","神秘礼物"},
{"351","洒水器","“洒水器”已出现在地下室","在不受到伤害的情况下，通过第一章。","洒水器"},
{"352","愤怒苍蝇","“愤怒苍蝇”已出现在地下室","在一局游戏中，拾取3个标签“苍蝇”的道具。","愤怒苍蝇"},
{"353","派对帽","“派对帽”已出现在地下室","摧毁5个彩虹大便。","派对帽"},
{"354","损坏的调制解调器","“损坏的调制解调器”已出现在地下室","每日挑战胜利7次。","损坏的调制解调器"},
{"355","伙伴盲盒","“伙伴盲盒”已出现在地下室","在一局游戏中，获得5个跟班。","伙伴盲盒"},
{"356","快速炸弹","“快速炸弹”已出现在地下室","击败小角恶魔20次。","快速炸弹"},
{"357","精神错乱宝宝","“精神错乱宝宝”已出现在地下室","击败精神错乱1次。","精神错乱宝宝"},
{"358","发夹","“发夹”已出现在地下室","拾取电池20次。","发夹"},
{"359","木十字架","“木十字架”已出现在地下室","使用床1次。","木十字架"},
{"360","黄油！","“黄油！”已出现在地下室","在一局游戏中，完成跑圈2次。","黄油！"},
{"361","卡牌变巨术","“卡牌变巨术”已出现在地下室","在一局游戏中，让角色变大5次。","变巨术"},
{"362","卡牌先祖召唤","“卡牌先祖召唤”已出现在地下室","使用卡牌20次。","先祖召唤"},
{"363","卡牌时空漫步","“卡牌时空漫步”已出现在地下室","收集图鉴中的怀表和损坏的怀表。","时空漫步"},
{"364","代金券","“代金券”已出现在地下室","进行商店交易和恶魔交易共50次。","代金券"},
{"365","念力","“念力”已出现在地下室","在不受到伤害的情况下，通过第二章。","念力"},
{"366","搬家盒","“搬家盒”已出现在地下室","在暗室中，使用潘多拉魔盒。","搬家盒"},
{"367","跨接电缆","“跨接电缆”已出现在地下室","在一局游戏中，拾取2个标签“电池”的道具。","跨接电缆"},
{"368","麻风病","“麻风病”已出现在地下室","在不受到伤害的情况下，通过第三章。","麻风病"},
{"369","科技零","“科技零”已出现在地下室","在一局游戏中，拾取2个标签“科技”的道具。","科技零"},
{"370","银丝羽毛","“银丝羽毛”已出现在地下室","在一局游戏中，拾取钥匙碎片1和钥匙碎片2。","银丝羽毛"},
{"371","自我先生！","“自我先生！”已出现在地下室","打开金箱子和永恒箱子共20次。","自我先生！"},
{"372","七印","“七印”已出现在地下室","击败饥荒骑士、瘟疫骑士、战争骑士、征服骑士和死亡骑士各1次。","七印"},
{"373","天使棱镜","“天使棱镜”已出现在地下室","击败乌列和加百列共20次。","天使棱镜"},
{"374","噗！","“噗！”已出现在地下室","在不受到伤害的情况下，通过第四章。","噗！"},
{"375","门挡","“门挡”已出现在地下室","炸开房间的门或隐藏房50次。","门挡"},
{"376","死神名册","“死神名册”已出现在地下室","进行恶魔交易25次。","死神名册"},
{"377","泪血症","“泪血症”已出现在地下室","拾取血块10次。","泪血症"},
{"378","食泪症","“食泪症”已出现在地下室","在一局游戏中，拾取10个标签“射速上升”的道具。","食泪症"},
{"379","书包","“书包”已出现在地下室","在一局游戏中，进入6个商店。","书包"},
{"380","三圣颂","“三圣颂”已出现在地下室","在天使房中，拾取道具25次。","三圣颂"},
{"381","扩接电线","“扩接电线”已出现在地下室","收集图鉴中的蓄电池、9伏特、车载电池。","扩接电线"},
{"382","扁石","“扁石”已出现在地下室","拾取橡胶胶水5次。","扁石"},
{"383","祭坛","“祭坛”已出现在地下室","进行恶魔交易50次。","祭坛"},
{"384","呕吐虫宝宝","“呕吐虫宝宝”已出现在地下室","被角色自己的爆炸眼泪炸死。","呕吐虫宝宝"},
{"385","毛毯","“毛毯”已出现在地下室","使用床10次。","毛毯"},
{"386","弹珠袋","“弹珠袋”已出现在地下室","在一局游戏中，使用咕噜！5次。","弹珠袋"},
{"387","神秘的卵","“神秘的卵”已出现在地下室","在一个房间中，同时拥有3个具有魅惑状态的敌人。","神秘的卵"},
{"388","腐烂硬币","“腐烂硬币”已出现在地下室","在一局游戏中，同时拥有20个蓝苍蝇。","腐烂硬币"},
{"389","儿童弯勺","“儿童弯勺”已出现在地下室","叠加2层追踪效果。","儿童弯勺"},
{"390","遗骸","你解锁了“遗骸”","使用妈妈的铲子挖开碎土块。","遗骸"},
{"391","骨心","“骨头心”已出现在地下室","解锁遗骸。","骨心"},
{"392","骨髓","“骨髓”已出现在地下室","用遗骸获得困难妈妈的心脏通关标记。","骨髓"},
{"393","滑肋骨","“滑肋骨”已出现在地下室","用遗骸获得以撒通关标记。","滑肋骨"},
{"394","尖肋骨","“尖肋骨”已出现在地下室","用遗骸获得撒但通关标记。","尖肋骨"},
{"395","颌骨","“颌骨”已出现在地下室","用遗骸获得???通关标记。","颌骨"},
{"396","成骨不全症","“成骨不全症”已出现在地下室","用遗骸获得羔羊通关标记。","脆骨症"},
{"397","离婚协议书","“离婚协议书”已出现在地下室","用遗骸获得Boss Rush通关标记。","离婚协议书"},
{"398","圣地大便","“圣地大便”已出现在地下室","用遗骸获得死寂通关标记。","圣地大便"},
{"399","指骨","“指骨”已出现在地下室","用遗骸获得贪婪模式通关标记。","指骨"},
{"400","爸爸的戒指","“爸爸的戒指”已出现在地下室","用遗骸获得困难贪婪模式通关标记。","爸爸的戒指"},
{"401","亡者之书","“亡者之书”已出现在地下室","用遗骸获得精神错乱通关标记。","亡者之书"},
{"402","骨头宝宝","“骨头宝宝”已出现在地下室","用遗骸在困难模式下获得所有通关标记。","骨头宝宝"},
{"403","羁绊宝宝","“羁绊宝宝”已出现在地下室","用遗骸获得超级撒但通关标记。","羁绊宝宝"},
{"404","伯大尼","你解锁了“伯大尼”","用拉撒路在困难模式下通关第四章且未死亡。","伯大尼"},
{"405","雅各和以扫","你解锁了“雅各&以扫”","击败母亲1次。","雅各和以扫"},
{"406","星象房","星辰在召唤…","在一局游戏中，拾取3个标签“星星”的道具。","星象房"},
{"407","秘密出口","你解锁了“秘密出口”","击败死寂3次。","秘密出口"},
{"408","失落摇篮曲","“失落摇篮曲”已出现在地下室","炸开塞壬的头颅。","失落摇篮曲"},
{"409","果味甜蝇宝","“果味甜蝇宝”已出现在地下室","击败糖梅宝宝10次。","甜甜糖梅宝"},
{"410","甜蝇溜溜笛","“甜蝇溜溜笛”已出现在地下室","让糖梅宝宝逃跑。","糖梅溜溜笛"},
{"411","腐心","“腐心”已出现在地下室","进入尸宫1次。","腐心"},
{"412","污水井","你解锁了“污水井”","击败下水道中的所有头目。","污水井"},
{"413","灰坑","你解锁了“灰坑”","击败矿洞中的所有头目。","灰坑"},
{"414","炼狱","你解锁了“炼狱”","击败陵墓中的所有头目。","炼狱"},
{"415","红钥匙","“红钥匙”已出现在地下室","打开妈妈的箱子。","红钥匙"},
{"416","魂火宝宝","你解锁了“魂火宝宝”","用伯大尼获得困难模式妈妈的心脏通关标记。","魂火宝宝"},
{"417","美德之书","“美德之书”已出现在地下室","用伯大尼获得以撒通关标记。","美德之书"},
{"418","灵魂之瓮","“灵魂之瓮”已出现在地下室","用伯大尼获得撒但通关标记。","灵魂之瓮"},
{"419","神圣硬币","“神圣硬币”已出现在地下室","用伯大尼获得???通关标记。","神圣硬币"},
{"420","白玉香膏盒","“白玉香膏盒”已出现在地下室","用伯大尼获得羔羊通关标记。","白玉香膏盒"},
{"421","伯大尼的信仰","“伯大尼的信仰”已出现在地下室","用伯大尼获得Boss Rush通关标记。","伯大尼的信仰"},
{"422","灵魂吊坠","“灵魂吊坠”已出现在地下室","用伯大尼获得贪婪模式通关标记。","灵魂吊坠"},
{"423","神圣干预","“神圣干预”已出现在地下室","用伯大尼获得死寂通关标记。","神圣干预"},
{"424","驱魔护符","“驱魔护符”已出现在地下室","用伯大尼获得困难贪婪模式通关标记。","驱魔护符"},
{"425","伯列恒之星","“伯列恒之星”已出现在地下室","用伯大尼获得精神错乱通关标记。","伯列恒之星"},
{"426","希望宝宝","你解锁了“希望宝宝”","用伯大尼获得所有困难通关标记。","希望宝宝"},
{"427","发光宝宝","你解锁了“发光宝宝”","用伯大尼获得超级撒但通关标记。","发光宝宝"},
{"428","连体宝宝","你解锁了“连体宝宝”","用雅各和以扫获得困难模式妈妈的心脏通关标记。","连体宝宝"},
{"429","天堂阶梯","“天堂阶梯”已出现在地下室","用雅各和以扫获得以撒通关标记。","天堂阶梯"},
{"430","红豆汤","“红豆汤”已出现在地下室","用雅各和以扫获得撒但通关标记。","红豆汤"},
{"431","长子名分","“长子名分”已出现在地下室","用雅各和以扫获得???通关标记。","长子名分"},
{"432","达摩克里斯之剑","“达摩克里斯之剑”已出现在地下室","用雅各和以扫获得羔羊通关标记。","达摩克里斯之剑"},
{"433","谷底石","“谷底石”已出现在地下室","用雅各和以扫获得Boss Rush通关标记。","谷底石"},
{"434","内在孩童","“内在孩童”已出现在地下室","用雅各和以扫获得贪婪模式通关标记。","内在孩童"},
{"435","消失的胞胎","“消失的胞胎”已出现在地下室","用雅各和以扫获得死寂通关标记。","消失的胞胎"},
{"436","创世记","“创世记”已出现在地下室","用雅各和以扫获得困难贪婪模式通关标记。","创世记"},
{"437","背摔！","“背摔！”已出现在地下室","用雅各和以扫获得精神错乱通关标记。","背摔！"},
{"438","所罗门宝宝","你解锁了“所罗门宝宝”","用雅各和以扫获得所有困难通关标记。","所罗门宝宝"},
{"439","幻象宝宝","你解锁了“幻象宝宝”","用雅各和以扫获得超级撒但通关标记。","幻象宝宝"},
{"440","切肉刀","“切肉刀”已出现在地下室","用以撒获得母亲通关标记。","切肉刀"},
{"441","选择？","“选择？”已出现在地下室","用以撒获得祸兽通关标记。","选择？"},
{"442","难吃的心","“难吃的心”已出现在地下室","用抹大拉获得母亲通关标记。","难吃的心"},
{"443","糖心","“糖心”已出现在地下室","用抹大拉获得祸兽通关标记。","糖心"},
{"444","嗝屁猫的眼睛","“嗝屁猫的眼睛”已出现在地下室","用该隐获得母亲通关标记。","嗝屁猫的眼睛"},
{"445","一磅肉","“一磅肉”已出现在地下室","用该隐获得祸兽通关标记。","一磅肉"},
{"446","血田","“血田”已出现在地下室","用犹大获得母亲通关标记。","血田"},
{"447","赎罪","“赎罪”已出现在地下室","用犹大获得祸兽通关标记。","赎罪"},
{"448","永恒六面骰","“永恒六面骰”已出现在地下室","用???获得母亲通关标记。","永恒六面骰"},
{"449","水土不服症","“水土不服症”已出现在地下室","用???获得祸兽通关标记。","水土不服症"},
{"450","鸟肥笼","“鸟肥笼”已出现在地下室","用夏娃获得母亲通关标记。","鸟肥笼"},
{"451","碎裂的宝珠","“碎裂的宝珠”已出现在地下室","用夏娃获得祸兽通关标记。","碎裂的宝珠"},
{"452","嗜血腥风","“嗜血腥风”已出现在地下室","用参孙获得母亲通关标记。","嗜血腥风"},
{"453","空虚之心","“空虚之心”已出现在地下室","用参孙获得祸兽通关标记。","空虚之心"},
{"454","恶魔王冠","“恶魔王冠”已出现在地下室","用阿撒泻勒获得母亲通关标记。","恶魔王冠"},
{"455","亚巴顿宝宝","“亚巴顿宝宝”已出现在地下室","用阿撒泻勒获得祸兽通关标记。","亚巴顿宝宝"},
{"456","小畸胎瘤","“小畸胎瘤”已出现在地下室","用拉撒路获得母亲通关标记。","小畸胎瘤"},
{"457","灵魂出窍","“灵魂出窍”已出现在地下室","用拉撒路获得祸兽通关标记。","灵魂出窍"},
{"458","'M","“'M”已出现在地下室","用伊甸获得母亲通关标记。","'M"},
{"459","百宝罐","“百宝罐”已出现在地下室","用伊甸获得祸兽通关标记。","百宝罐"},
{"460","迷失游魂","“迷失游魂”已出现在地下室","用游魂获得母亲通关标记。","迷失游魂"},
{"461","饥饿幽魂","“饥饿幽魂”已出现在地下室","用游魂获得祸兽通关标记。","饥饿幽魂"},
{"462","嗜血小宠","“嗜血小宠”已出现在地下室","用莉莉丝获得母亲通关标记。","嗜血小宠"},
{"463","剖腹产","“剖腹产”已出现在地下室","用莉莉丝获得祸兽通关标记。","剖腹产"},
{"464","店主的胯袋","“店主的胯袋”已出现在地下室","用店主获得母亲通关标记。","店主的胯袋"},
{"465","店主的盒子","“店主的盒子”已出现在地下室","用店主获得祸兽通关标记。","店主的盒子"},
{"466","黑洞宝宝","“黑洞宝宝”已出现在地下室","用亚玻伦获得母亲通关标记。","黑洞宝宝"},
{"467","触手朋友","“触手朋友”已出现在地下室","用亚玻伦获得祸兽通关标记。","触手朋友"},
{"468","骨刺","“骨刺”已出现在地下室","用遗骸获得母亲通关标记。","骨刺"},
{"469","灵魂枷锁","“灵魂枷锁”已出现在地下室","用遗骸获得祸兽通关标记。","灵魂枷锁"},
{"470","终末天启","“终末天启”已出现在地下室","用伯大尼获得母亲通关标记。","终末天启"},
{"471","魂火罐","“魂火罐”已出现在地下室","用伯大尼获得祸兽通关标记。","魂火罐"},
{"472","玄奇驴皮","“玄奇驴皮”已出现在地下室","用雅各和以扫获得母亲通关标记。","玄奇驴皮"},
{"473","寻友护符","“寻友护符”已出现在地下室","用雅各和以扫获得祸兽通关标记。","寻友护符"},
{"474","神伤者","你解锁了“以撒”","用以撒在家的红色贮藏室中唤醒自己。","堕化以撒"},
{"475","无畏者","你解锁了“抹大拉”","用抹大拉在家的红色贮藏室中唤醒自己。","堕化抹大拉"},
{"476","囤积者","你解锁了“该隐”","用该隐在家的红色贮藏室中唤醒自己。","堕化该隐"},
{"477","背叛者","你解锁了“犹大”","用犹大在家的红色贮藏室中唤醒自己。","堕化犹大"},
{"478","污秽者","你解锁了“???”","用???在家的红色贮藏室中唤醒自己。","堕化???"},
{"479","血凝者","你解锁了“夏娃”","用夏娃在家的红色贮藏室中唤醒自己。","堕化夏娃"},
{"480","残暴者","你解锁了“参孙”","用参孙在家的红色贮藏室中唤醒自己。","堕化参孙"},
{"481","堕落者","你解锁了“阿撒泻勒”","用阿撒泻勒在家的红色贮藏室中唤醒自己。","堕化阿撒泻勒"},
{"482","迷离者","你解锁了“拉撒路”","用拉撒路在家的红色贮藏室中唤醒自己。","堕化拉撒路"},
{"483","无常者","你解锁了“伊甸”","用伊甸在家的红色贮藏室中唤醒自己。","堕化伊甸"},
{"484","受难者","你解锁了“游魂”","用游魂在家的红色贮藏室中唤醒自己。","堕化游魂"},
{"485","浪荡者","你解锁了“莉莉丝”","用莉莉丝在家的红色贮藏室中唤醒自己。","堕化莉莉丝"},
{"486","吝财者","你解锁了“店主”","用店主在家的红色贮藏室中唤醒自己。","堕化店主"},
{"487","空虚者","你解锁了“亚玻伦”","用亚玻伦在家的红色贮藏室中唤醒自己。","堕化亚玻伦"},
{"488","受缚者","你解锁了“遗骸”","用遗骸在家的红色贮藏室中唤醒自己。","堕化遗骸"},
{"489","狂信者","你解锁了“伯大尼”","用伯大尼在家的红色贮藏室中唤醒自己。","堕化伯大尼"},
{"490","流亡者","你解锁了“雅各”","用雅各和以扫在家的红色贮藏室中唤醒自己。","堕化雅各"},
{"491","错误王冠","“错误王冠”已出现在地下室","用堕化以撒获得祸兽通关标记。","错误王冠"},
{"492","肚肚软糖","“肚肚软糖”已出现在地下室","用堕化抹大拉获得祸兽通关标记。","肚肚软糖"},
{"493","蓝钥匙","“蓝钥匙”已出现在地下室","用堕化该隐获得祸兽通关标记。","蓝钥匙"},
{"494","血色羁绊","“血色羁绊”已出现在地下室","用堕化犹大获得祸兽通关标记。","血色羁绊"},
{"495","虫群","“虫群”已出现在地下室","用堕化???获得祸兽通关标记。","虫群"},
{"496","心碎","“心碎”已出现在地下室","用堕化夏娃获得祸兽通关标记。","心碎"},
{"497","声带","“声带”已出现在地下室","用堕化参孙获得祸兽通关标记。","声带"},
{"498","阿撒泻勒之怒","“阿撒泻勒之怒”已出现在地下室","用堕化阿撒泻勒获得祸兽通关标记。","阿撒泻勒之怒"},
{"499","救恩","“救恩”已出现在地下室","用堕化拉撒路获得祸兽通关标记。","救恩"},
{"500","错误技","“错误技”已出现在地下室","用堕化伊甸获得祸兽通关标记。","错误技"},
{"501","十字圣球","“十字圣球”已出现在地下室","用堕化游魂获得祸兽通关标记。","十字圣球"},
{"502","作孽双子","“作孽双子”已出现在地下室","用堕化莉莉丝获得祸兽通关标记。","作孽双子"},
{"503","稻草人","“稻草人”已出现在地下室","用堕化店主获得祸兽通关标记。","稻草人"},
{"504","回声室","“回声室”已出现在地下室","用堕化亚玻伦获得祸兽通关标记。","回声室"},
{"505","以撒的坟墓","“以撒的坟墓”已出现在地下室","用堕化遗骸获得祸兽通关标记。","以撒的坟墓"},
{"506","复仇之魂","“复仇之魂”已出现在地下室","用堕化伯大尼获得祸兽通关标记。","复仇之魂"},
{"507","小以扫","“小以扫”已出现在地下室","用堕化雅各获得祸兽通关标记。","小以扫"},
{"508","血腥玛丽","你解锁了挑战#37血腥玛丽","解锁它还活着、伯大尼和血袋。","挑战#37：血腥玛丽"},
{"509","圣火洗礼","你解锁了挑战#38圣火洗礼","解锁它还活着、灵魂之瓮和抹大拉的信仰。","挑战#38：圣火洗礼"},
{"510","以撒织梦岛","你解锁了挑战#39以撒织梦岛","击败母亲1次。","挑战#39：以撒织梦岛"},
{"511","重影幻视","你解锁了挑战#40重影幻视","解锁雅各和以扫。","挑战#40：重影幻视"},
{"512","异食游戏","你解锁了挑战#41异食游戏","解锁它还活着和弹珠袋。","挑战#41：异食游戏"},
{"513","烫手山芋","你解锁了挑战#42烫手山芋","解锁堕化遗骸。","挑战#42：烫手山芋"},
{"514","大量过牌！","你解锁了挑战#43大量过牌！","解锁堕化该隐。","挑战#43：大量过牌！"},
{"515","赤键救赎","你解锁了挑战#44赤键救赎","解锁堕化雅各。","挑战#44：赤键救赎"},
{"516","删了这个","你解锁了挑战#45","解锁堕化伊甸。","挑战#45：　　　　"},
{"517","龌龊之心","“龌龊之心”已出现在地下室","通过挑战#36：掏粪男孩。","龌龊之心"},
{"518","巴风特之印","“巴风特之印”已出现在地下室","通过挑战#37：血腥玛丽。","巴风特之印"},
{"519","炼狱恶鬼","“炼狱恶鬼”已出现在地下室","通过挑战#38：圣火洗礼。","炼狱恶鬼"},
{"520","英灵剑","“英灵剑”已出现在地下室","通过挑战#39：以撒织梦岛。","英灵剑"},
{"521","碎掉的眼镜","“碎掉的眼镜”已出现在地下室","通过挑战#40：重影幻视。","碎掉的眼镜"},
{"522","冰块","“冰块”已出现在地下室","通过挑战#41：异食游戏。","冰块"},
{"523","充能硬币","“充能硬币”已出现在地下室","向电池乞丐捐赠，使其奖励道具5次。","充能硬币"},
{"524","愚者","“愚者”已出现在地下室","用堕化游魂获得困难贪婪模式通关标记。","0-愚者？"},
{"525","魔术师","“魔术师”已出现在地下室","用堕化犹大获得困难贪婪模式通关标记。","I-魔术师？"},
{"526","女祭司","“女祭司”已出现在地下室","用堕化莉莉丝获得困难贪婪模式通关标记。","II-女祭司？"},
{"527","皇后","“皇后”已出现在地下室","用堕化夏娃获得困难贪婪模式通关标记。","III-皇后？"},
{"528","皇帝","“皇帝”已出现在地下室","用堕化???获得困难贪婪模式通关标记。","IV-皇帝？"},
{"529","教皇","“教皇”已出现在地下室","用堕化伯大尼获得困难贪婪模式通关标记。","V-教皇？"},
{"530","恋人","“恋人”已出现在地下室","用堕化抹大拉获得困难贪婪模式通关标记。","VI-恋人？"},
{"531","战车","“战车”已出现在地下室","通过挑战#42：烫手山芋。","VII-战车？"},
{"532","正义","“正义”已出现在地下室","通过挑战#43：大量过牌！。","VIII-正义？"},
{"533","隐者","“隐者”已出现在地下室","通过挑战#44：赤键救赎。","IX-隐者？"},
{"534","命运之轮","“命运之轮”已出现在地下室","用堕化该隐获得困难贪婪模式通关标记。","X-命运之轮？"},
{"535","力量","“力量”已出现在地下室","用堕化参孙获得困难贪婪模式通关标记。","XI-力量？"},
{"536","倒吊人","“倒吊人”已出现在地下室","用堕化店主获得困难贪婪模式通关标记。","XII-倒吊人？"},
{"537","死亡","“死亡”已出现在地下室","用堕化遗骸获得困难贪婪模式通关标记。","XIII-死亡？"},
{"538","节制","“节制”已出现在地下室","通过挑战#45：　　　　。","XIV-节制？"},
{"539","恶魔","“恶魔”已出现在地下室","用堕化阿撒泻勒获得困难贪婪模式通关标记。","XV-恶魔？"},
{"540","塔","“塔”已出现在地下室","用堕化亚玻伦获得困难贪婪模式通关标记。","XVI-塔？"},
{"541","星星","“星星”已出现在地下室","用堕化以撒获得困难贪婪模式通关标记。","XVII-星星？"},
{"542","太阳与月亮","“太阳&月亮”已出现在地下室","用堕化雅各获得困难贪婪模式通关标记。","XVIII-月亮？"},
{"543","审判","“审判”已出现在地下室","用堕化拉撒路获得困难贪婪模式通关标记。","XX-审判？"},
{"544","世界","“世界”已出现在地下室","用堕化伊甸获得困难贪婪模式通关标记。","XXI-世界？"},
{"545","老旧电容","“老旧电容”已出现在地下室","消灭电池乞丐10次。","老旧电容"},
{"546","硫磺火炸弹","“硫磺火炸弹”已出现在地下室","在岩角恶魔逃跑前消灭它。","硫磺火炸弹"},
{"547","超级蘑菇","“超级蘑菇”已出现在地下室","用所有非堕化人物获得所有困难通关标记。","超级蘑菇"},
{"548","妈妈的发髻","“妈妈的发髻”已出现在地下室","用堕化以撒获得以撒、???、撒但和羔羊通关标记。","妈妈的发髻"},
{"549","骰子袋","“骰子袋”已出现在地下室","用堕化以撒获得母亲通关标记。","骰子袋"},
{"550","神圣王冠","“神圣王冠”已出现在地下室","用堕化抹大拉获得以撒、???、撒但和羔羊通关标记。","神圣王冠"},
{"551","母亲的吻","“母亲的吻”已出现在地下室","用堕化抹大拉获得母亲通关标记。","母亲的吻"},
{"552","镀金钥匙","“镀金钥匙”已出现在地下室","用堕化该隐获得以撒、???、撒但和羔羊通关标记。","镀金钥匙"},
{"553","幸运袋","“幸运袋”已出现在地下室","用堕化该隐获得母亲通关标记。","幸运袋"},
{"554","你的灵魂","“你的灵魂”已出现在地下室","用堕化犹大获得以撒、???、撒但和羔羊通关标记。","你的灵魂"},
{"555","数字冰箱贴","“数字冰箱贴”已出现在地下室","用堕化犹大获得母亲通关标记。","数字冰箱贴"},
{"556","粪蛋","“粪蛋”已出现在地下室","用堕化???获得以撒、???、撒但和羔羊通关标记。","粪蛋"},
{"557","火药圈","“火药圈”已出现在地下室","用堕化???获得母亲通关标记。","火药圈"},
{"558","奇怪的钥匙","“奇怪的钥匙”已出现在地下室","用堕化夏娃获得以撒、???、撒但和羔羊通关标记。","奇怪的钥匙"},
{"559","小血团","“小血团”已出现在地下室","用堕化夏娃获得母亲通关标记。","小血团"},
{"560","纹身贴","“纹身贴”已出现在地下室","用堕化参孙获得以撒、???、撒但和羔羊通关标记。","纹身贴"},
{"561","被吞下的M80鞭炮","“被吞下的M80鞭炮”已出现在地下室","用堕化参孙获得母亲通关标记。","被吞下的M80鞭炮"},
{"562","邪恶王冠","“邪恶王冠”已出现在地下室","用堕化阿撒泻勒获得以撒、???、撒但和羔羊通关标记。","邪恶王冠"},
{"563","阿撒泻勒的残角","“阿撒泻勒的残角”已出现在地下室","用堕化阿撒泻勒获得母亲通关标记。","阿撒泻勒的残角"},
{"564","破损的口袋","“破损的口袋”已出现在地下室","用堕化拉撒路获得以撒、???、撒但和羔羊通关标记。","破损的口袋"},
{"565","扑克牌残片","“扑克牌残片”已出现在地下室","用堕化拉撒路获得母亲通关标记。","扑克牌残片"},
{"566","滚啊！","“滚啊！”已出现在地下室","用堕化伊甸获得以撒、???、撒但和羔羊通关标记。","滚啊！"},
{"567","塑型黏土","“塑型黏土”已出现在地下室","用堕化伊甸获得母亲通关标记。","塑型黏土"},
{"568","儿童涂鸦","“儿童涂鸦”已出现在地下室","用堕化游魂获得以撒、???、撒但和羔羊通关标记。","儿童涂鸦"},
{"569","水晶钥匙","“水晶钥匙”已出现在地下室","用堕化游魂获得母亲通关标记。","水晶钥匙"},
{"570","双胞胎","“双胞胎”已出现在地下室","用堕化莉莉丝获得以撒、???、撒但和羔羊通关标记。","双胞胎"},
{"571","领养协议书","“领养协议书”已出现在地下室","用堕化莉莉丝获得母亲通关标记。","领养协议书"},
{"572","店主的协议","“店主的协议”已出现在地下室","用堕化店主获得以撒、???、撒但和羔羊通关标记。","店主的协议"},
{"573","诅咒硬币","“诅咒硬币”已出现在地下室","用堕化店主获得母亲通关标记。","诅咒硬币"},
{"574","蟋蟀腿","“蟋蟀腿”已出现在地下室","用堕化亚玻伦获得以撒、???、撒但和羔羊通关标记。","蟋蟀腿"},
{"575","亚玻伦的挚友","“亚玻伦的挚友”已出现在地下室","用堕化亚玻伦获得母亲通关标记。","亚玻伦的挚友"},
{"576","抛光骨头","“抛光骨头”已出现在地下室","用堕化遗骸获得以撒、???、撒但和羔羊通关标记。","抛光骨头"},
{"577","空壳心","“空壳心”已出现在地下室","用堕化遗骸获得母亲通关标记。","空壳心"},
{"578","扩展电路板","“扩展电路板”已出现在地下室","用堕化伯大尼获得以撒、???、撒但和羔羊通关标记。","扩展电路板"},
{"579","伯大尼的精华","“伯大尼的精华”已出现在地下室","用堕化伯大尼获得母亲通关标记。","伯大尼的精华"},
{"580","赛车遥控器","“赛车遥控器”已出现在地下室","用堕化雅各获得以撒、???、撒但和羔羊通关标记。","赛车遥控器"},
{"581","复得游魂","“复得游魂”已出现在地下室","用堕化雅各获得母亲通关标记。","复得游魂"},
{"582","会员卡","“会员卡”已出现在地下室","在单个商店中，消费40个以上的硬币。","会员卡"},
{"583","金剃刀片","“金剃刀片”已出现在地下室","在一局游戏中，拥有99硬币，然后全部花光。","金剃刀片"},
{"584","计数二十面骰","“计数二十面骰”已出现在地下室","用堕化以撒获得精神错乱通关标记。","计数二十面骰"},
{"585","高凝血","“高凝血”已出现在地下室","用堕化抹大拉获得精神错乱通关标记。","高凝血"},
{"586","合成宝袋","“合成宝袋”已出现在地下室","用堕化该隐获得精神错乱通关标记。","合成宝袋"},
{"587","暗仪刺刀","“暗仪刺刀”已出现在地下室","用堕化犹大获得精神错乱通关标记。","暗仪刺刀"},
{"588","大肠激躁症","“大肠激躁症”已出现在地下室","用堕化???获得精神错乱通关标记。","大肠激躁症"},
{"589","圣血吸管","“圣血吸管”已出现在地下室","用堕化夏娃获得精神错乱通关标记。","圣血吸管"},
{"590","狂怒！","“狂怒！”已出现在地下室","用堕化参孙获得精神错乱通关标记。","狂怒！"},
{"591","咯血症","“咯血症”已出现在地下室","用堕化阿撒泻勒获得精神错乱通关标记。","咯血症"},
{"592","生死逆转","“生死逆转”已出现在地下室","用堕化拉撒路获得精神错乱通关标记。","生死逆转"},
{"593","存档错误","“存档错误”已出现在地下室","用堕化伊甸获得精神错乱通关标记。","隐藏房和错误房生成的道具有概率变为错误道具"},
{"594","幽灵炸弹","“幽灵炸弹”已出现在地下室","用堕化游魂获得精神错乱通关标记。","幽灵炸弹"},
{"595","格罗","“格罗”已出现在地下室","用堕化莉莉丝获得精神错乱通关标记。","格罗"},
{"596","店主的亲友","“店主的亲友”已出现在地下室","用堕化店主获得精神错乱通关标记。","店主的亲友"},
{"597","无底坑","“无底坑”已出现在地下室","用堕化亚玻伦获得精神错乱通关标记。","无底坑"},
{"598","飞头攻击","“飞头攻击”已出现在地下室","用堕化遗骸获得精神错乱通关标记。","飞头攻击"},
{"599","所罗门魔典","“所罗门魔典”已出现在地下室","用堕化伯大尼获得精神错乱通关标记。","所罗门魔典"},
{"600","孤魂铁索","“孤魂铁索”已出现在地下室","用堕化雅各获得精神错乱通关标记。","孤魂铁索"},
{"601","大箱子","“大箱子”已出现在地下室","用堕化以撒获得超级撒但通关标记。","大箱子"},
{"602","红桃Q","“红桃Q”已出现在地下室","用堕化抹大拉获得超级撒但通关标记。","红桃Q"},
{"603","金胶囊","“金胶囊”已出现在地下室","用堕化该隐获得超级撒但通关标记。","金胶囊"},
{"604","黑福袋","“黑福袋”已出现在地下室","用堕化犹大获得超级撒但通关标记。","黑福袋"},
{"605","友好大便","“友好大便”已出现在地下室","用堕化???获得超级撒但通关标记。","友好大便"},
{"606","大胶囊","“大胶囊”已出现在地下室","用堕化夏娃获得超级撒但通关标记。","大胶囊"},
{"607","夹娃娃机","“夹娃娃机”已出现在地下室","用堕化参孙获得超级撒但通关标记。","夹娃娃机"},
{"608","地狱抽奖","“地狱抽奖”已出现在地下室","用堕化阿撒泻勒获得超级撒但通关标记。","地狱抽奖"},
{"609","木箱子","“木箱子”已出现在地下室","用堕化拉撒路获得超级撒但通关标记。","木箱子"},
{"610","万用牌","“万用牌”已出现在地下室","用堕化伊甸获得超级撒但通关标记。","万用牌"},
{"611","闹鬼箱子","“闹鬼箱子”已出现在地下室","用堕化游魂获得超级撒但通关标记。","闹鬼箱子"},
{"612","愚人金","“愚人金”已出现在地下室","用堕化莉莉丝获得超级撒但通关标记。","愚人金"},
{"613","金硬币","“金硬币”已出现在地下室","用堕化店主获得超级撒但通关标记。","金硬币"},
{"614","腐烂乞丐","“腐烂乞丐”已出现在地下室","用堕化亚玻伦获得超级撒但通关标记。","腐烂乞丐"},
{"615","金电池","“金电池”已出现在地下室","用堕化遗骸获得超级撒但通关标记。","金电池"},
{"616","忏悔室","“忏悔室”已出现在地下室","用堕化伯大尼获得超级撒但通关标记。","忏悔室"},
{"617","金饰品","“金饰品”已出现在地下室","用堕化雅各获得超级撒但通关标记。","金饰品"},
{"618","以撒的魂石","“以撒的魂石”已出现在地下室","用堕化以撒获得Boss Rush和死寂通关标记。","以撒的魂石"},
{"619","抹大拉的魂石","“抹大拉的魂石”已出现在地下室","用堕化抹大拉获得Boss Rush和死寂通关标记。","抹大拉的魂石"},
{"620","该隐的魂石","“该隐的魂石”已出现在地下室","用堕化该隐获得Boss Rush和死寂通关标记。","该隐的魂石"},
{"621","犹大的魂石","“犹大的魂石”已出现在地下室","用堕化犹大获得Boss Rush和死寂通关标记。","犹大的魂石"},
{"622","???的魂石","“???的魂石”已出现在地下室","用堕化???获得Boss Rush和死寂通关标记。","???的魂石"},
{"623","夏娃的魂石","“夏娃的魂石”已出现在地下室","用堕化夏娃获得Boss Rush和死寂通关标记。","夏娃的魂石"},
{"624","参孙的魂石","“参孙的魂石”已出现在地下室","用堕化参孙获得Boss Rush和死寂通关标记。","参孙的魂石"},
{"625","阿撒泻勒的魂石","“阿撒泻勒的魂石”已出现在地下室","用堕化阿撒泻勒获得Boss Rush和死寂通关标记。","阿撒泻勒的魂石"},
{"626","拉撒路的魂石","“拉撒路的魂石”已出现在地下室","用堕化拉撒路获得Boss Rush和死寂通关标记。","拉撒路的魂石"},
{"627","伊甸的魂石","“伊甸的魂石”已出现在地下室","用堕化伊甸获得Boss Rush和死寂通关标记。","伊甸的魂石"},
{"628","游魂的魂石","“游魂的魂石”已出现在地下室","用堕化游魂获得Boss Rush和死寂通关标记。","游魂的魂石"},
{"629","莉莉丝的魂石","“莉莉丝的魂石”已出现在地下室","用堕化莉莉丝获得Boss Rush和死寂通关标记。","莉莉丝的魂石"},
{"630","店主的魂石","“店主的魂石”已出现在地下室","用堕化店主获得Boss Rush和死寂通关标记。","店主的魂石"},
{"631","亚玻伦的魂石","“亚玻伦的魂石”已出现在地下室","用堕化亚玻伦获得Boss Rush和死寂通关标记。","亚玻伦的魂石"},
{"632","遗骸的魂石","“遗骸的魂石”已出现在地下室","用堕化遗骸获得Boss Rush和死寂通关标记。","遗骸的魂石"},
{"633","伯大尼的魂石","“伯大尼的魂石”已出现在地下室","用堕化伯大尼获得Boss Rush和死寂通关标记。","伯大尼的魂石"},
{"634","雅各与以扫的魂石","“雅各","用堕化雅各获得Boss Rush和死寂通关标记。","雅各与以扫的魂石"},
{"635","奇怪的门","一扇奇怪的门在深牢出现","击败母亲1次。","奇怪的门"},
{"636","死亡证明","“死亡证明”已出现在地下室","用所有人物获得所有困难通关标记。","死亡证明"},
{"637","弑神大神","弑神大神！","解锁所有其他成就并收集所有物品。",""}
};

*/
