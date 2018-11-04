#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "ѩɽ��Ȫ");
   set("long", @LONG
��������ɽ�����֮���һ����Ȫ(quan)��һ����Ȫ����˻
˻��ˮ�����ȵ�ˮ�����紵ɢ�����¹����γ�һ���Ű�ɫ�Ļ�����
����ѩɽ֮�ϣ���Ȼ���д˵��������֮�����಻�����˸�̾��
��֮���档�̲���ˮ�У�Ʈ���Ŷ��ѩ�����꣬ƬƬѩ��ƮȻ��
�£���ˮ�������磬�㼴�׷׻�Ϊ�����ɢ���������������Ĵ�
ѩɽ֮�ϣ�Ω����������������컨����ݡ�һ����Ů����Ȫ
�������仨�������������¡�
LONG);
        set("outdoors", "lingxiao"); 
    	set("resource/water", 1);
    	set("objects", ([
           	__DIR__"npc/a-xiu" : 1,
    	]) );
        set("exits", ([ 
     		"east" :__DIR__"sroad6",
	]));
        set("item_desc", ([
                "quan" : HIC "����ɽ�����һ����Ȫ������ף��ƺ�����"
                         "Ǳ(dive)��ȥ��\n" NOR,
        ]) );
        setup(); 
}

void init()
{       
        add_action("do_dive", "dive");
}

int do_dive(string arg)
{
        object me = this_player();

        if ((arg != "quan" || ! arg))
                return notify_fail("��ҪǱʲô��\n");

   		message_vision(HIY "ֻ��$N" HIY "������һ����������ͨ��һ"
                               "����������������Ȫ��\n" NOR, me);

        if ((int)me->query_skill("force") < 100)
	{ 
   		message_vision(HIR "$N" HIY "����ˮ���ã�����������Ǳ��ˮ"
                               "ѹ������Ҳ���ܲ�ס���͵ش���������\n"
                               NOR, me);
        } else 
        {
		message_vision(HIY "$N" HIY "ֻ��ѹ��Խ��Խ������ǿ����"
                               "��������֧�֣���������Ǳȥ����\n\n" NOR +
                               HIC "ֻ��ˮ�л���һ������ƽ�������ˡ�\n" NOR,
                               this_player()); 
                me->move(__DIR__"wave1"); 
        } 
        return 1;
}

