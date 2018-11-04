#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_tiao(string arg);

void create()
{
        set("short", "ˮ������");
        set("long", 
"ˮ�������ϸǷ��£��ϸǷ�֮ˮ����ɽ�������ϸ��ɶ�֮\n�У���ɲ⣬"
"ˮ�����磬����(pubu)�߶�ʮ���ɣ�����������\nƮй���£�εΪ׳�ۡ�"
"���ž���ʫԻ��" HIW "����孺�������Ī��\n���ӵ�����������������������"
"ˮ����������ͷ��" NOR "������̾��\n��ɽ���ľ�֮һ�� ˮ����֮�� ��\n"
);
        set("exits", ([ 
               "westdown"    : __DIR__"shanlu12",
	       "northeast"   : __DIR__"shanlu15",	
        ]));

        set("no_clean_up", 0);

        set("outdoors", "henshan");

        set("item_desc",([
	        "pubu" : HIG "\nֻ���ٲ���к���£����ư��磬����׳�ۣ�����ȴ"
                         "��������Ԩ��\nһ���޵ף�ˮ����ȴƫƫ���ٲ�֮��\n\n" NOR,
	]));

        setup();
}


void init()
{
        add_action("do_tiao", ({"tiao", "jump"}));
}

int do_tiao(string arg)
{
        string msg;
        object obj, me = this_player();
        int skill_dodge;

        skill_dodge = me->query_skill("dodge", 1);

        if (! obj = find_object(__DIR__"inhole")) 
		obj = load_object(__DIR__"inhole");
            
        if (! arg || (arg != "pubu" && arg != "�ٲ�"))
        {	
        	write("�������Ķ�����\n");
        	return 1;
        }	

        if (skill_dodge < 60)
        {	
        	message_vision(HIC "\n$N" HIC "ʹ����ǰһԾ���ۼ�Ҫ�����ڣ���$N"
                               HIC "�о������Ѿ������ڰ�\n��ȴ���ٲ�������ȥ��\n\n"
                               NOR, me);

         	tell_object(me, HIW "�����Ժ��������ļ���ˮ��������ߣ�����"
                                "ȴ��һ������Ҳʹ\n��������\n\n" NOR, me);

        	me->move(__DIR__"heishatan");
        	me->unconcious();     

        	return 1;
	}

        if (skill_dodge < 140)
        {
             	message_vision(HIC "\n$N" HIC "������ǰһ������Щ���ٲ����䣬���о�"
                               "���գ�$N" HIC "�������ڶ��ڴ���������ȴ�����Ǳ���\n\n" 
                               NOR, me);
        	me->move(obj);
        	message("vision", HIW "\n" + me->name() + HIW "���ٲ������Ǳ���ֵ�"
                                  "���˽�����\n\n" NOR, obj, me);

        	return 1;
        }

        msg = HIC "\n$N" HIC "������ǰһ�ݣ����ɵ����ڶ��ڴ���\n\n" NOR;	
        message_vision(msg, me);
        me->move(obj);
        message("vision", HIW "\n" + me->name() + HIW "���ٲ������˽�����\n" NOR, 
                          obj, me);

       	return 1;
}
