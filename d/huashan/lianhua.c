// Room: /d/huashan/lianhua.c
// Modify by Rcwiz for hero.cd

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "������");
        set("long", @LONG
̫�����壭���������壬Ҳ��ܽ�ط壬�嶥��һ���ʯ��״������������
���ۡ��ô��ɴ˵������������¶��ͣ�����ǧ�𣬵���Զ����tiao�����ش�ç
ç��μ�����ˮ����������嶥��ʯ����ժ��ʯ����ȡ���ֿ�ժ�ǳ���֮�⣬
��״����֮�ߡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
             "eastdown" : __DIR__"chengxiang",
        ]));

        set("item_desc", ([
               "jianzhong" : "̫Զ���Ʋ������\n",
        ]));

        set("outdoors", "huashan");

        setup();
}
 
void init()
{
        object me = this_player();
        if (me->query_temp("xunshan")) me->set_temp("xunshan/lianhua", 1);

        add_action("do_tiao", "tiao");
        add_action("do_jump", "jump");

        return;
}

int do_tiao()
{
        object me = this_player();

        write(@LONG
����Զ���ͱ���һ����������磬��������ͱ��в����Լ��ʮ���ɴ�����
��һ�������ɼ����Ĵ�ʯ������һ��ƽ̨��ʯ�������̵����֡���Ŀ��������
������ǡ���ڣ����jianzhong���������֡�
LONG);

        return 1;
}

int do_jump(string arg)
{
        object me = this_player();

        if (! arg || arg != "jianzhong")
             return notify_fail("��Ҫ���Ķ�����\n");

        if (me->query("qi") < 300)
             return notify_fail("���������ӡ�\n");

        if (me->is_busy() || me->is_fighting())
             return notify_fail("����æ������˵��\n");

        me->start_busy(1 + random(3));

        if (me->query_skill("dodge", 1) < 200 || me->query_str() < 30)
        {
             message_vision(HIG "$N" HIG "��һ�������ܸ����ߣ������������ͱ���ȥ ����\n"
                            HIR "$N" HIR "����ʮ���ɣ���Ȼ�������ӣ�����ˤ��������������Ѫֱ����\n" NOR, me);
   
             me->receive_wound("qi", me->query("qi") / 2, me);        
            
             return 1;
        }

        message_sort(HIG "\n$N" HIG "����Ծ�𣬴ܸ����ߣ�����̤���ͱ��ϵ�С��֮�У���"
                     "�Ŵ��������׼һ����̦���˽�ȥ������ų���ʯ���Ͼ�Ȼ����һ��"
                     "СѨ�������㣬$N" HIG "����һ������˫��ץסʯ����ͻ����ʯ�飬�͵�"
                     "����һԾ���������ͱڡ�\n" NOR, me);

       me->move(__DIR__"jianzhong");
      
       return 1;
}

