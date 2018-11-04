#include <ansi.h>
inherit ROOM;

int room_status = 0;
int *big = allocate(2);
int *res = allocate(2);

int random2 (int i)
{
        return (random(i) + uptime()) % i;
}

mapping gutous = ([ 
	"tc" : "ͷ��",
        "sd" : "˫��",
        "qx" : "����",
        "sx" : "ɢ��",
 ]); 

void create()
{
        set("short", "�ĳ�");
        set("long", @LONG
������������СС�Ķ�����ֻҪ��˵�����Ķľߣ�����
���С��������������������ľ�����Ů�ǳԳԵ�Ц����������
�Ĵ�ţ����������������������㼸���Ϳ���������������
����ص�������ǽ�Ϲ���һ������(paizi)��
LONG);
        set("exits", ([
                "south" : __DIR__"duchang",
        ]));
        set("item_desc", ([
                "paizi" : WHT "        ��������������������������������������\n"
                              "        ��                                  ��\n"
                              "        ��             " NOR + HIW "�Ĳ�����" NOR + WHT "             ��\n"
                              "        ��                                  ��\n"
                              "        ��                                  ��\n"
                              "        ��  " NOR + HIW "ͷ��" NOR + WHT " <" NOR + HIC "tc" NOR + WHT "> ������ÿ�ο���ǰȷ��  ��\n"
                              "        ��            ���ʣ�һӮ��ʮ��      ��\n"
                              "        ��                                  ��\n"
                              "        ��  " NOR + HIW "˫��" NOR + WHT " <" NOR + HIC "sd" NOR + WHT "> ��������ͬ����Ϊż��  ��\n"
                              "        ��            ���ʣ�һӮʮ��        ��\n"
                              "        ��                                  ��\n"
                              "        ��  " NOR + HIW "����" NOR + WHT " <" NOR + HIC "qx" NOR + WHT "> ��������֮��Ϊ��      ��\n"
                              "        ��            ���ʣ�һӮ��          ��\n"
                              "        ��                                  ��\n"
                              "        ��  " NOR + HIW "ɢ��" NOR + WHT " <" NOR + HIC "sx" NOR + WHT "> ��Ϊ�����壬�ţ�ʮһ  ��\n"
                              "        ��            ���ʣ�һӮ��          ��\n"
                              "        ��                                  ��\n"
                              "        ��  " NOR + HIW "����" NOR + WHT "��                          ��\n"
                              "        ��                                  ��\n"
                              "        ��                                  ��\n"
                              "        ��   " NOR + HIY "bet  " NOR + HIC "ѹ������" NOR + HIY "  ����  ��������" NOR + WHT "  ��\n"
                              "        ��                                  ��\n"
                              "        ��                                  ��\n"
                              "        ��                                  ��\n"
                              "        ��������������������������������������\n\n\n" NOR,
        ]));
        set("objects", ([
                "/d/beijing/npc/duke" : 2,
                "/d/changan/npc/zhuangjia" : 1,
        ]));
        set("no_fight", 1);
        setup();
}
void init()
{
	if (! interactive(this_player()))
		return;

        add_action("do_bet", "bet");

        if (room_status > 0)
        	return;

        remove_call_out("gamble_prepare");
        remove_call_out("gamble_start");
        remove_call_out("gamble_perform");
        remove_call_out("gamble_finish");
        call_out ("gamble_prepare", 2);
        room_status = 1;
}

int do_bet(string arg)
{
        object me = this_player();
        string what;
        int amount;
        string money;
        object ob;
        object zj;

        if (! objectp(zj = present("zhuang jia", this_object())))
                return notify_fail("ׯ�Ҷ�û�У���Ҫ��˭�ģ�\n");

        if (! living(zj))
                return notify_fail("�㻹�ǵ�ׯ��������˵�ɣ�\n");

        if (! arg || sscanf (arg,"%s %d %s", what, amount, money) != 3)
                return notify_fail(CYN "�Ŀͼ�Ц������������������Ǯ�ģ�\n" NOR);

        if (what != "tc" &&
            what != "sd" &&
            what != "qx" &&
            what != "sx")
                return notify_fail(CYN "ׯ����ü������ҪѺ��һ������\n" NOR);

        ob = present(money + "_money", me);
        if (! ob)
                return notify_fail(CYN "ׯ����ü����������û������Ǯ�ɣ�\n" NOR);

        if (amount < 1)
                return notify_fail(CYN "ׯ����ü������ô�٣��������������ٶ�Ѻ�㡣\n" NOR);

        if (amount > ob->query_amount())
                return notify_fail(CYN "ׯ����ü����������ô��Ǯ��\n" NOR);

	if (amount > 10)
		return notify_fail(CYN "ׯ�Һ�������ô�����������ô�ࣿ������Ʊ������ע��\n" NOR);

	if (ob->query("base_value") * amount > 100000)
		return notify_fail(CYN "ׯ�Ҵ���������ע���ʮ���ƽ�\n" NOR);

        if (me->query_temp("gamble_bet/amount") > 0)
                return notify_fail(CYN "ׯ�ҵ������Ѿ�Ѻ���ˣ��͵��ſ��Ѱɡ�\n" NOR);

        if (room_status > 1)
                return notify_fail(CYN "ׯ����Ц�����������ڶ��أ������Ե�Ƭ�̡�\n" NOR);

        me->set_temp("gamble_bet/kind", what);
        me->set_temp("gamble_bet/amount", amount);
        me->set_temp("gamble_bet/money", money);
        message_vision(sprintf("$N�ó�%s%s%s��Ѻ��%s�ϡ�\n",
                               chinese_number(amount),
                               ob->query("base_unit"),
                               ob->query("name"),
                               gutous[what]),
                               me);
        if (amount == ob->query_amount())
                destruct (ob);
        else
                ob->add_amount(-amount);

        if (! arrayp(query_temp("better")))
                set_temp("better", ({ me }));
        else
                add_temp("better", ({ me }));

        return 1;
}

int valid_leave(object me, string dir)
{
        if (dir == "south")
        {
                if (me->query_temp ("gamble_bet/amount") > 0) 
                message_vision (CYN "$N" CYN "����Ѻ����Ǯ����Ҫ�ˡ�\n" NOR, me);
                me->delete_temp("gamble_bet");
        }
        return ::valid_leave(me,dir);
}

void display_bet(object room, int i)
{
        string str;
        switch (i)
        {
        case 1:
                str = 
"����������\n"+
"����������\n"+
"�����񡡩�\n"+
"����������\n"+
"����������\n";

                break;
        case 2:
                str = 
"����������\n"+
"����������\n"+
"���񡡡�\n"+
"����������\n"+
"����������\n";
                break;
        case 3:
                str =
"����������\n"+
"���񡡡���\n"+
"�����񡡩�\n"+
"��������\n"+
"����������\n";
                break;
        case 4:
                str = 
"����������\n"+
"���񡡡�\n"+
"����������\n"+
"���񡡡�\n"+
"����������\n";
                break;
        case 5:
                str =
"����������\n"+
"���񡡡�\n"+
"�����񡡩�\n"+
"���񡡡�\n"+
"����������\n";
                break;
        case 6:
                str = 
"����������\n"+
"���񡡡�\n"+
"���񡡡�\n"+
"���񡡡�\n"+
"����������\n";
                break;
        }
        tell_room(room,str);
}

int rdm()
{
        return random2(6) + 1;
}

void gamble_prepare()
{
        object room = this_object();
        tell_room (room, CYN "ׯ�ҳ������¿��̣�Ԥ��ͷ�ʣ�\n" NOR);
        tell_room (room, CYN "ׯ�ҽ���ö������������һ����\n" NOR);
        big[0] = rdm();
        big[1] = rdm();
// keep two numbers different for a probability == 1/36
        while (big[0] == big[1])
        {
                reset_eval_cost();
                big[1] = rdm();
        }
        display_bet(room,big[0]);
        display_bet(room,big[1]);
        tell_room(room, CYN "\nׯ�ҽе���ͷ�������ǡ�" HIY + chinese_number(big[0]) +
                        NOR + CYN "���͡�" HIY + chinese_number(big[1]) + NOR + CYN
                        "����\n\n" NOR);
        tell_room(room, CYN "����ׯ��������˳�ֽ������������ջأ����ڿ���ѺǮ��\n" NOR);
        room_status = 1;
        call_out("gamble_start",24);
        delete_temp("better");
}
 
void gamble_start()
{
        object room = this_object();
        tell_room (room, CYN "ׯ�Һ���������ͣѺ��\n" NOR);
        tell_room (room, CYN "\n����ׯ���ֲ��е�������ͷ�������ǡ�" HIY +
                         chinese_number(big[0]) + NOR + CYN "���͡�" HIY +
                         chinese_number(big[1]) + NOR + CYN "����\n\n" NOR);

        tell_room (room, CYN "Ȼ��ׯ�ҽ���ö�����ӽ��������ѣ�һ�ֳ�һ��ҡ��������\n" NOR);
        room_status = 2;
        call_out("gamble_perform", 6, 0);
        call_out("gamble_perform", 12, 1);
        call_out("gamble_finish", 18);
}
void gamble_perform (int i)
{
        object room = this_object();
        tell_room(room, HIY "\n���ѵ����������ϣ��������˳�����\n" NOR);
        res[i] = rdm();
        display_bet (room,res[i]);
}

void player_wins(object who, int total)
{
        object money = new("/clone/money/" +
                           who->query_temp("gamble_bet/money"));
        int amount = who->query_temp("gamble_bet/amount");
        total = total * amount;
        money->set_amount(total);
        message_vision(sprintf("$NӮ��%s%s%s��\n",
                       chinese_number(total),
                       money->query("base_unit"),
                       money->query("name")),
                       who);
        money->move(who);
}

void player_loses(object who, int total)
{
        object money = new("/clone/money/" +
			   who->query_temp("gamble_bet/money"));
        total = who->query_temp("gamble_bet/amount");
        message_vision(sprintf("ׯ�ҽ�$NѺ�������е�%s%s%s���ߡ�\n",
                               chinese_number(total),
                               money->query("base_unit"),
                               money->query("name")),
                               who);
        destruct(money);
}

void gamble_finish()
{
        string win;
        int total, i;
        object room = this_object();
        object *list;

        if (res[0]==big[0] && res[1]==big[1])
        {
                total = 36;
                win = "tc";
        } else
        if (res[0]==res[1] && (res[0]/2*2 == res[0]))
        {
                total = 12;
                win = "sd";
        } else 
        {
                int r = res[0]+res[1];
                if (r==7)
                {
                        total = 6;
                        win = "qx";
                } else if (r==3 || r==5 || r==9 || r==11) 
                {
                        total = 3;
                        win = "sx";
                } else
                {
                        total = 0;
                        win = "none of them";
                }
        }
        if (total == 0)
                tell_room(room, CYN "ׯ�ҽе���" + chinese_number(res[0]) +
                                chinese_number(res[1]) + "�������̣�\n" NOR);
        else
                tell_room(room, CYN "ׯ�ҽе���" + chinese_number(res[0]) +
                                chinese_number(res[1])+"����" + gutous [win] +
                                 "��\n" NOR);

        list = query_temp("better");
        i = sizeof(list);
        while (i--)
        {
                if (! objectp(list[i]))
                        continue;

                if (environment(list[i]) == room)
                {
                        if (list[i]->query_temp("gamble_bet/kind") == win)
                                player_wins(list[i],total); else
                        if (list[i]->query_temp("gamble_bet/kind"))
                                player_loses(list[i],total);
                }

                list[i]->delete_temp("gamble_bet");
        }
        tell_room (room,"\n");
        call_out ("gamble_prepare",5);
}

