#include <ansi.h>
inherit ROOM;

int sos(int,int);
void fresh(object ob);

void create()
{
        set("short", "�ĳ�");
        set("long", @LONG
�����ǶĴ�С�ķ��䣬���ܵĶķ��ﴫ����ߺ������Ķ�
����������ĳ���ģ���㲻�Ϻܴ󣬵��ĵ�����ȴ����ȫ����
��Ҳ�ǳ��ܵ��������ǽ�Ϲ���һ������(paizi)��
LONG);
        set("item_desc", ([
                "paizi" : WHT "\n\n        ������������������������������\n"
                              "        ��                          ��\n"
                              "        ��         " NOR + HIW "�Ĳ�����" NOR + WHT "         ��\n"
                              "        ��                          ��\n"
                              "        ��      ������ɫ������һֻ  ��\n"
                              "        ��  ���ɫ�ӵ����ܺ�����  ��\n"
                              "        ��  ��ʮ��ΪС��ʮһ��ʮ��  ��\n"
                              "        ��  Ϊ��������ɫ�ӵ�����  ��\n"
                              "        ��  ͬ�����Сͨ�ԡ�������  ��\n"
                              "        ��  ��С��С������һ����  ��\n"
                              "        ��  �ܸ��ֻ���Ϊ��ע���޶�  ��\n"
                              "        ��  Ϊ��ʮ����١�          ��\n"
                              "        ��                          ��\n"
                              "        ��  " NOR + HIW "����" NOR + WHT "��                  ��\n"
                              "        ��                          ��\n"
                              "        ��          " NOR + HIY "big" NOR + WHT "             ��\n"
                              "        ��   " NOR + HIY "gamble" NOR + HIW "  |" NOR + HIY "  ����  ����" NOR + WHT "  ��\n"
                              "        ��         " NOR + HIY "small" NOR + WHT "            ��\n"
                              "        ��                          ��\n"
                              "        ��                          ��\n"
                              "        ������������������������������\n\n\n" NOR,
        ]));
        set("exits", ([
                "east" : __DIR__"duchang",
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
        add_action("do_gamble", "gamble");
}

int do_gamble(string arg)
{
        int a,b,c;
        int wager, skill, lpoint, tpoint;
        string wtype1, wtype2, status;
        object mtype, me;
        mapping lrn;

        int min, max;
        min = 50;
        max = 500000;

        me = this_player();

        if (me->query_temp("casino/mark"))
                return notify_fail(CYN "�Ŀͽе������������ڻ�û�ֵ����ء�\n" NOR);

        if (! arg || sscanf(arg, "%s %d %s", wtype1, wager, wtype2) != 3)
                return notify_fail(CYN "�Ŀͼ�Ц������������������Ǯ�ģ�\n" NOR);

        mtype = present(wtype2 + "_money", me);

        if (! mtype)
		return notify_fail("������û�����ֻ��ҡ�\n");

        if (wager < 1)
		return notify_fail("��Ҫѹ���ٰ���\n");

        if ((int)mtype->query_amount() < wager)
                return notify_fail("������û����ô��" + mtype->query("name") + "��\n");

        if (wager > 50)
		return notify_fail(CYN "ׯ����ü������ô��ô���������飿ȥ��������������\n" NOR);

        if (wager * (mtype->query("base_value")) < min
           || wager * (mtype->query("base_value")) > max)
        	return notify_fail("��Ķ�ע�����޶�֮�ڡ�\n");

        if ((wtype1 != "big") && (wtype1 != "small") )
                return notify_fail("��Ҫ�Ĵ��Ƕ�С��\n");

        me->set_temp("gamb_t",(me->query_temp("gamb_t") +1));

        if (me->query_temp("gamb_t") > 50)
        {
                call_out("fresh", 300, me);
                me->set_temp("casino/mark", 1);
                return notify_fail(CYN "�Ŀͽе�����λ" + RANK_D->query_respect(me) +
                                   CYN "���������ô�ã�Ҳ�û����˰ɣ�\n" NOR);
        }

        a = random(6) + 1;
        b = random(6) + 1;
        c = random(6) + 1;

        message_vision(HIW "\nׯ�Һȵ�������" + chinese_number(a) + "��"
                       + chinese_number(b) + "��" + chinese_number(c) +
                       "��", me);

        if ((a == b) && (b == c) )
                message_vision("��Сͨɱ��\n\n" NOR, me);

        else if ((a + b + c) > 10)
                message_vision("��С���\n\n" NOR, me);

        else if ((a + b + c) < 11)
                message_vision("�Դ���С��\n\n" NOR, me);

        if (((a == b) && (b == c))
           || ((a + b + c) > 10 && (wtype1 == "small"))
           || ((a + b + c) < 11 && (wtype1 == "big")))
                status = "lose";

        if ( status == "lose")
	{
        	message_vision(me->query("name") + "����" + chinese_number(wager) +
                               mtype->query("base_unit") + mtype->query("name") +
                               "��\n", me);
                mtype->set_amount((int)mtype->query_amount() - wager);
                mtype->move(me, 1);
        } else
	{
       		message_vision(me->query("name") + "Ӯ��" + chinese_number(wager) +
                               mtype->query("base_unit") + mtype->query("name") +
                               "��\n", me);
                mtype->set_amount((int)mtype->query_amount() + wager);
                mtype->move(me, 1);
        }
        return 1;
}

void fresh(object ob)
{
	if (! objectp(ob)) return;
        ob->delete_temp("gamb_t");
        ob->delete_temp("casino/mark");
}

int sos(int lower, int upper)
{
        int x,y;
        x = 0;

        while (lower <= upper)
        {
                y = lower * lower;
                x += y;
                lower++;
        }
        return x;
}
