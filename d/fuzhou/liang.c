#include <ansi.h>
inherit ROOM;

#define JIASHA    "/clone/lonely/book/kuihua3"

void create()
{ 
       set("short", "����");
       set("long", @LONG
�������ҵķ��������¹��ƣ���Χȫ����Щ��ľͷ��ש�ߡ�
LONG );
        set("exits", ([
                "down" : __DIR__"mishi",
        ]));
        "/clone/lonely/book/kuihua3"->foo();
        setup();
}

void init()
{       
        object me = this_player(), ob;
        int exp, pot, sc;

        exp = 10000 + random(3000);
        pot = 1000 + random(300);
        sc = random(50);

        ob = find_object(JIASHA);
        if (! ob) ob = load_object(JIASHA);

        if (! objectp(ob))
                return 0;

        if (! objectp(present("jia sha", this_object())))
                return 0;

        if (! (int)me->query("skybook/xiaoao/baodian"))
        {
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("score", sc);
                tell_object(me, HIY "\n���Ծ�Ϸ�������ʱ����һ�����İڷ����С�\n\n"
                                NOR + HIW "��ɹ����ҵ��˿������䣡\n" NOR + HIC
                                "ͨ����ε�������������" + chinese_number(exp) +
                                "�㾭�顢" + chinese_number(pot) + "��Ǳ\n���Լ�"
                                + chinese_number(sc) + "�㽭��������\n\n" NOR);
                me->set("skybook/xiaoao/baodian", 1);
        } else
                tell_object(me, HIY "\n���Ծ�Ϸ�������ʱ����һ�����İڷ����С�\n\n" NOR);
}

