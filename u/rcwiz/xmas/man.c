// modify by rcwiz!

inherit NPC;

#include <ansi.h>

void init();

string give_gift();

int i = 0;

// 低级物品
string* throw_gift1 = ({
               "/clone/fam/gift/con1",
               "/clone/fam/gift/str1",
               "/clone/fam/gift/dex1",
               "/clone/fam/gift/int1",
               "/clone/fam/pill/food",
               "/clone/fam/pill/food1",
               "/clone/fam/pill/linghui1",
               "/clone/fam/pill/lingzhi1",
               "/clone/fam/pill/neili1",
               "/clone/fam/pill/puti1",
               "/clone/fam/pill/renshen1",
               "/clone/fam/pill/water",
               "/clone/fam/pill/xuelian1",
               "/clone/food/baozi",
               "/clone/food/fish",
               "/clone/food/jiudai",
               "/clone/food/peanut",
               "/clone/food/xia",
               "/clone/money/gold",
               "/clone/gift/jinkuai",
               "/clone/poison/kongquedan",
               "/clone/poison/hedinghong",
               "/clone/poison/wushengsan",
               "/clone/fam/item/stone1",
               "/clone/fam/item/stone2",
               "/clone/tattoo/face1",
               "/clone/tattoo/face2",
               "/clone/tattoo/face3",
               "/clone/tattoo/face4",
});

// 中级物品
string* throw_gift2 = ({
               "/clone/fam/gift/int2",
               "/clone/fam/gift/str2",
               "/clone/fam/gift/con2",
               "/clone/fam/gift/dex2",
               "/clone/fam/etc/va2",
               "/clone/fam/etc/va3",
               "/clone/fam/etc/va4",
               "/clone/fam/etc/va5",
               "/clone/fam/item/stone3",
               "/clone/fam/item/stone4",
               "/clone/fam/item/stone5",
               "/clone/fam/item/taijin",
               "/clone/fam/item/wujin",               
               "/clone/food/baozi",
               "/clone/food/fish",
               "/clone/food/jiudai",
               "/clone/food/peanut",
               "/clone/food/xia",
               "/clone/money/gold",
               "/clone/gift/jinkuai",
               "/clone/fam/pill/linghui2",
               "/clone/fam/pill/lingzhi2",
               "/clone/fam/pill/renshen2",
               "/clone/fam/pill/neili2",
               "/clone/fam/pill/puti1",
               "/clone/fam/pill/sheli1",
               "/clone/fam/pill/xuelian2",
               "/clone/fam/pill/yulu",
               "/clone/tattoo/body1",
               "/clone/tattoo/body2",
               "/clone/tattoo/body4",
               "/clone/tattoo/buttock4",
               "/clone/tattoo/spc1",
               "/clone/tattoo/spc9",
               "/clone/tattoo/face8",
});

// 高级物品
string* throw_gift3 = ({
               "/clone/tattoo/spc7",
               "/clone/tattoo/per1",
               "/clone/tattoo/spc6",
               "/clone/tattoo/body9",
               "/clone/fam/item/stone5",
               "/clone/fam/item/taijin",
               "/clone/fam/item/wujin",
               "/clone/food/baozi",
               "/clone/food/fish",
               "/clone/food/jiudai",
               "/clone/food/peanut",
               "/clone/food/xia",
               "/clone/money/gold",
               "/clone/gift/jinkuai",
               "/clone/fam/pill/neili2",
               "/clone/fam/pill/puti1",
               "/clone/fam/pill/sheli1",
               "/clone/fam/pill/xuelian2",
               "/clone/fam/pill/yulu",
               "/clone/fam/gift/int3",
               "/clone/fam/gift/con3",
               "/clone/fam/gift/dex3",
               "/clone/fam/gift/str3",
               "/clone/fam/max/longjia",
               "/clone/fam/item/jiulei",
               "/clone/fam/item/yinzhu",
               "/clone/fam/pill/dimai",
               "/clone/fam/pill/lingzhi4",
               "/clone/fam/pill/renshen4",
               "/clone/fam/pill/sheli4",
});


string* start_words = ({
               HIW "   ♀  " HIR "ΜΕΥΥΨ   ΣΥΙξΤΜΑξ   "HIW"♀" NOR,
               HIW "大家快快到成都提督府前广场来，我要发礼物了！" NOR,
               HIW "现在我开始倒数十声 ……" NOR,
               HIW "Ten ……" NOR,
               HIW "Nine ……" NOR,
               HIW "Eight ……" NOR,
               HIW "Seven ……" NOR,
               HIW "Six ……" NOR,
               HIW "Five ……" NOR,
               HIW "Four ……" NOR,
               HIW "Three ……" NOR,
               HIW "Two ……" NOR,
               HIW "One ……" NOR,
               HIW "哈哈，张大你们的眼睛，接着吧 %·￥%！·……" NOR,
               HIW "圣诞老人将手伸进一个大口袋里，似乎在摸什么东西 ……" NOR,
});

void create()
{
	set_name(HIR "圣诞" HIW "老人" NOR, ({ "christmas man", "man", "lao ren" }) );
	set("gender", "男性" );
	set("age", 65);
	set("long", HIM "圣诞老人背着一个大口袋，笑嘻嘻地看着你！\n" NOR);
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 80);
	set("dex", 82);
	set("con", 80);
	set("int", 81);

        set("max_qi", 30000);
        set("max_jing", 18000);
        set("neili", 32000);
        set("max_neili", 32000);
        set("jiali", 550);
        set("combat_exp", 15000000);
        set("score", 100000);

        set_skill("force", 600);
        set_skill("kuihua-mogong", 600);
        set_skill("dodge", 600);
        set_skill("unarmed", 600);
        set_skill("parry", 600);
        set_skill("literate", 600);
        set_skill("martial-cognize", 460);

        map_skill("force", "kuihua-mogong");
        map_skill("dodge", "kuihua-mogong");
        map_skill("unarmed", "kuihua-mogong");
        map_skill("parry", "kuihua-mogong");

        prepare_skill("unarmed", "kuihua-mogong");

        set("inquiry", ([
                "圣诞快乐" : (: give_gift :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.tian" :),
                (: perform_action, "unarmed.qiong" :),
                (: perform_action, "unarmed.bian" :),
                (: perform_action, "unarmed.sheng" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
        }));

	set("attitude", "friendly");
	setup();

	carry_object(__DIR__"ccloth")->wear();

	add_money("silver", 3);
}

void init()
{
        command("say 圣诞快乐！Merry Christmas！");
}

string give_gift()
{
        object me;
        object gift;
        me = this_player();
    
        // 已经领取过礼物
        if (me->query("get_christmas_gift/y2002"))
                 return HIR "“Merry Christmas！”\n" NOR;
        
        // 已经吃过礼物
        if (me->query("eat_christmas_gift/y2002"))
                 return HIR"“Merry Christmas！”\n" NOR;

        // 给予礼物
        message_vision(HIY "圣诞老人笑嘻嘻地对$N说道：“Merry Christmas！”\n" NOR, me);
        command("smile");
        command("say 恩，我给你找找礼物！你等等！");
        message_vision(HIY "圣诞老人将背上的大口袋放在地方，翻来翻去……\n", me);
        command("haha");
        command("say 好了，你的礼物，给你吧！");
        message_vision(HIY "圣诞老人将礼物给$N" HIY "\n", me);        
        tell_object(me, HIG "你得到了一个礼物，快看看吧！\n");
        
        switch(random(5))
        {
             case 1 :
                  gift = new(__DIR__"jitui");
                  gift->move(me);
                  break;

             case 2 :
                  gift = new(__DIR__"hanbao");
                  gift->move(me);
                  break;
 
             case 3 :                  
                  gift = new(__DIR__"dabing");
                  gift->move(me);
                  break;

             default :
                  gift = new(__DIR__"chang");
                  gift->move(me);
                  break;

        }        
        me->set("get_christmas_gift/y2002", 1);
        return "Bye！\n";
          
}

  void closeD_channel_start_words()
{
       remove_call_out("channel_start_words");
       if (i == sizeof(start_words))
       {
              i = 0;
              call_out("start_throw_gift", 1);
              return;
       }

       CHANNEL_D->do_channel(this_object(), "ic", start_words[i]);
       i += 1;

       call_out("channel_start_words", 3);

}

// 低级物品仍六次，中级仍三次，高级仍一次
void start_throw_gift()
{    
       string gift;
       object ob;
       int g;
       
       if (i < 6) // 仍低级物品
       {     
             g = sizeof(throw_gift1) - 1;
             gift = throw_gift1[random(g)];
             i ++;
       } else 
       if (i >= 6 && i < 9) // 仍低级物品
       {
             g = sizeof(throw_gift2) - 1;
             gift = throw_gift2[random(g)];
             i ++;
       } else
       if (i == 9) // 仍高级物品
       {
             if (random(100) == 1)gift = "/clone/fam/max/naobaijin";
             else if (random(40) == 1)gift = "/clone/fam/max/longjia";
             else
             {
                   g = sizeof(throw_gift3) - 1;
                   gift = throw_gift3[random(g)];
             }
             i ++;
       } else
       if (i >= 10)
       {
                CHANNEL_D->do_channel(this_object(), "ic", HIY "好了，好了，我口袋都空了，我也得走了。再次祝大家"
                                      "圣诞快乐，身体健康！" NOR);
                
                CHANNEL_D->do_channel(this_object(), "ic", HIY "希望大家能不懈地支持炎黄！再见！\n" + HIC "【异"
                                      "域传闻】圣诞老人坐着雪橇渐渐远去，叮当声也渐渐消失 ……" NOR);
               
                i = 0;

                return;
       }
    
       CHANNEL_D->do_channel(this_object(), "ic", HIW "Merry Christmas！\n" + HIC "【异域传闻】" HIR "圣诞老人随"
                             "手扔出一个礼物，礼物在空中打着旋儿，旋转着掉在了地上 ……" NOR);


       CHANNEL_D->do_channel(this_object(), "sys", HIM "系统报告： gift == " + gift + " ……" NOR);

       ob = new(gift);
       if (objectp(ob))
              ob->move("/d/city3/guangchang");

       remove_call_out("start_throw_gift");
       call_out("start_throw_gift", 1);
       
}

