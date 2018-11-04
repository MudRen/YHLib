//Room: shanhongpb.c ɽ���ٲ�
//Modify by Rcwiz for hero.cd

#include <ansi.h>

inherit ROOM;

string look_hongshui();

void create()
{
        set("short","ɽ���ٲ�");
        set("long",@LONG
������һ��Ͽ�ȣ�ÿ���꼾ɽ�鱬��ʱ���γ���һ��εΪ׳�۵�
�ٲ�����˵�������������������������ɾ��������������ġ�����
��ȥ�ȿգ�ֻʣ�¿��ȵ�ɽ�Ⱥͱ��ڵĺ�ˮ(hongshui)���������Ǹ�
���ӵĺ�ȥ����
LONG);
        set("outdoors", "huashan");
        set("item_desc", ([
                "hongshui" : (: look_hongshui :),
                "stone"    : NOR + WHT "һ����Ȼ�ľ�ʯ������ˮ����س�ʴ�š�\n" NOR,
        ]));
        set("exits",([ /* sizeof() == 1 */
                "southwest"     : __DIR__"shaluo",
        ]));
        setup();
}

void init()
{
        add_action("do_cross", "cross");
        add_action("do_jump", "jump");
}

string look_hongshui()
{
	return @DESC
����һ�ɱ��ڲ�Ϣ�ĺ�ˮ��ˮ�������и������ڷ��⣬���㶨��
��ϸһ����������ֻ������ˮ�淴����չ���ˡ�˳�ź�ˮ���ӣ�
ֻ���ٲ��״�����һ����Ȼ�ľ�ʯ��stone���� ����ٲ��ƺ���
�Դ�(cross)��ȥ��
DESC ;
}

int do_jump(string arg)
{
        object me = this_player();

        if (me->is_busy() || me->is_fighting())
              return notify_fail("��æ������˵�ɣ�\n");
    
        if (! arg || arg != "stone")
              return notify_fail("��Ҫ���Ķ�����\n");
 
        if (me->query_skill("dodge") < 240)
              return notify_fail("�㿴�˿��������Լ��Ṧ��Ϊ���ޣ�����óȻ���¡�\n");

        message_vision(HIG "$N" HIG "���������ٲ� ����\n", me);

        me->move(__DIR__"stone");

        return 1;
}

int do_cross()
{
        object me;       
        object cloth;

        me = this_player();
        if (me->query_dex() / 2 + random(me->query_dex()) < 22)
        {
                message_vision("$N���������ڵ��ٲ���ͻȻһԾ����ͼ����"
                               "�ٲ����������ͨ��һ��ˤ����ˮ�С�\n", me);

                cloth = me->query_temp("armor/cloth");
                if (cloth && cloth->washed(120 + random(120)))
                        tell_object(me, "�����ϵ�" + cloth->name() + "ʪ͸�ˣ�\n");
                return 1;
        }

        message_vision("$N���������ڵ��ٲ���ͻȻһԾ��������"
                       "�ٲ���\n", me);
        me->move(__DIR__"shandong");
        return 1;
}
