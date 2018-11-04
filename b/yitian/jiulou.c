#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ӣ��¥");
        set("long", @LONG
��Ӣ��¥�����νྻ�����п������κ��ݣ�ʮ�Ŷ��Ǹ���
��֡�������Ը�������Ͻ��ǵ�ȫ����
LONG);
        set("exits", ([
                "down" : "/d/beijing/huiying",
        ]));

        if (random(5) > 2)
        {
                set("story", 1);
                set("objects", ([
                        CLASS_D("gaibang") + "/ada" : 1,
                        __DIR__"npc/zhaomin2" : 1,
                        __DIR__"npc/zhao1" : 1,
                        __DIR__"npc/qian2" : 1,
                ]));
        }
        setup();
}

void init()
{
        if (query("story"))
        {
                remove_call_out("check");
                call_out("check", 800);
        }
}

void check()
{
        object ob = this_object();
        object npc1, npc2, npc3, npc4;

        npc1 = present("zhao min", ob);
        npc2 = present("a da", ob);
        npc3 = present("zhao yishang", ob);
        npc4 = present("qian erbai", ob);

        if (! npc1 || ! npc2)
                return 0;

        message_vision(CYN "$N" CYN "���˸���Ƿ��˵����ʱ�䲻"
                       "���ˣ����ǻ�ȥ�ɡ�\n$n" CYN "���˵�ͷ"
                       "�������ã���������߰ɡ�\n\n" HIY "˵"
                       "�ձ������һ��վ�𣬻���$N" HIY "�뿪"
                       "�˾�¥��\n\n" NOR, npc1, npc2);

        if (objectp(npc1))
                destruct(npc1);

        if (objectp(npc2))
                destruct(npc2);

        if (objectp(npc3))
                destruct(npc3);

        if (objectp(npc4))
                destruct(npc4);
}
