inherit ROOM;

#include <ansi.h> 

int do_take(string arg);

void create()
{
        set("short", "����");
        set("long", @LONG
�����������ǵı��� (che)��ɽ֮�����˱�����������Ϊ��
��ֱ��ɽ�ţ������ƶ��ɣ��ܴ���ѩɽ֮�۷��ٻ��£��Ǵ�ѩɽ
ȥ��ɽ�µĽ�ͨ���ߡ�����Գ���(take)����ɽ��
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            "east"  : __DIR__"iceroad3",
        ])); 
        set("objects", ([
                __DIR__"npc/dizi" : 1,
        ])); 

        set("item_desc", ([
        	"che": "һ̨���Ϻõĺ�ɼľ���Ƶı�����������������ɽ֮�á�\n"
        ]) );
        setup();
}
  
void init()
{
        add_action("do_take", "take");
}


int do_take(string arg)
{
        object me = this_player();

        if (! arg || arg != "che" )
                return notify_fail("��Ҫ��ʲô��\n");

        if (me->query("family/family_name") != "������")
                return notify_fail(CYN "�������ӵ������һ�ۣ���Ц�������Ը�û��"
                                   "�ȣ���Ҫ��ү�ҷ����㲻�ɣ�\n" NOR);

        message_vision(HIW "\n$N" HIW "���ȵ������ϱ��������������Ӵ�����ơ���"
                       "���ӵ��˵�ͷ����\n����һ�⣬������������֮�������·����"
                       "������ʱֻ������ѩɽ\n��$N" HIW "����Ź�����׾�֮�ţ�"
                       "����֮�С�$N" HIW "�����죬�̲�ס����\n��Х����һ���"
                       "��$N" HIW "�����ı����ѻ�����ɽ��֮�¡�\n\n" NOR,
                       this_player());

        me->move("/d/xuedao/sroad1");
        tell_object(me, HIC "��˳���ĵ�����ɽ���£�\n" NOR);

        message("vision", HIW "������ɽ���м��ٻ���һֻ������ͣ��ɽ��֮�¡�һ��"
                          "����һ�ݣ�Ծ�������������ǽý���\n" NOR,
                          environment(me), ({ me }));

        return 1;
}

