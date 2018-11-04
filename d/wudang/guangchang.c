#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�䵱�㳡");
        set("long", @LONG
����һ���ɴ�ʯ���̳ɵĹ㳡�����䵱����ѧϰ�书�ͻ�
���д�ĵص㡣��Χ��������ͩ����һ������������ص���Ҷ��
�и��������ĵ�ͯ���ڴ�ɨ���ϱ�������������
LONG);

        set("objects", ([
                CLASS_D("wudang") +"/daotong" : 2,
        ]));

        set("exits", ([
                "northdown"  : __DIR__"zixiaogate",
                "south"      : __DIR__"sanqingdian",
                "eastdown"   : __DIR__"tyroad1",
                "east"       : __DIR__"shanlu2",
        ]));

        set("outdoors", "wudang");
        setup();
}

void init()
{
        add_action("do_float", "float");
        add_action("do_float", "piao");
}

int do_float()
{
        object me;

        me = this_player();

        if (me->query_skill("tiyunzong", 1) < 120
           || me->query_skill("dodge", 1) < 120)
        {
                message_vision("$N��������ԭ�ر�����һ�����\n", me);
                return 1;
        }

        if (me->query("neili") < 100)
        {
                tell_object(me, "�������������������Ϣһ����˵�ɡ�\n");
                return 1;
        }

        me->add("neili", -70);

        message_sort(HIC "\n$N" HIC"����һ������������Ц��ֻ"
                     "������ƮȻ����̬�����ɣ��λ����Ƶ���"
                     "��ɽȥ�ˣ�Ц����Ȼδ����\n\n" NOR, me);
        me->move("/d/wudang/wdroad5");
        tell_object(me, "Ƭ�̣����Ѿ��䵽��ɽ���¡�\n");
        message("vision", "��Ȼһ��Ц��������ֻ��" + me->name() +
                "ƮȻ���£��������ɡ�\n", environment(me), ({ me }));
        return 1;
}
