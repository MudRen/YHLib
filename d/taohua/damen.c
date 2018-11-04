#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�һ�ɽׯ����");
	set("long",@LONG
�������һ��������š���ǰ��������˼����һ���������
�ô˵����˶��һ���ƫ�����ſ�վ������Сͯ���ش��š�����
���ڵش���Զ���̺��������Ƕ�ɽׯ�ķ��������ر��������
ǰ��һ�԰׵�(diao)��ë����ѩ����Ϊ�ɰ���
LONG);
	set("outdoors", "taohua");
	set("exits", ([
		"south" : __DIR__"qianyuan",
		"north" : __DIR__"tingzi",
		"east"  : __DIR__"road1" ,       
	]));
	set("item_desc", ([
		"diao" : HIW "\n��һ�԰׵���չ�����ɡ�������һ���"
                         "�ĵ��ӣ�����(" HIY "ride" HIW ")��\n����"
                         "�ɵ���ԭ���ǳ�������\n\n" NOR,
	]));
        set("objects", ([
                __DIR__"npc/shitong" : 2,
        ]));
        set("outdoors", "taohua");
        setup();
}

void init()
{
    	add_action("do_ride", "ride");
}

int do_ride(string arg)
{
    	object ob = this_player();

        if (! arg || arg != "diao" )
                return notify_fail("��Ҫ��ʲô��\n");

        if ((int)query("sb_ride"))
                return notify_fail("���ڰ׵��Ѿ����������ˣ��Ȼ�������ɡ�\n" ) ;

        if (ob->query("family/family_name") != "�һ���")
        {
      		message_vision(HIW "\n$N" HIW "һԾ������˰׵�ֻ���׵�"
                               "���쳤ণ�ͻȻ��Ȼһ�ߡ���\n" HIR "���$N"
                               HIR "ˤ�˸��������ף������׵��$N" HIR "��"
                               "��̫����Ȥ��\n" NOR, ob);
      		return 1;
    	}

    	add("sb_ride", 1);
    	message_vision(HIW "\n$N" HIW "һԾ������˰׵�ֻ���׵����쳤�"
                       "��ͻȻչ��߷ɡ���\n��һ��һ�����ν�����С��������"
                       "����\n\n" NOR, ob);

    	ob->move("/d/taohua/lantian") ;
    	tell_object(ob, HIW "\n�㲻�ϵط�ѽ�ɣ���ˮǧɽ����Ʈ������\n\n" NOR);
    	call_out("taohua", 1, ob);
    	return 1;
}

void taohua(object ob)
{
  	ob->move("/d/guiyun/qianyuan");
  	tell_object(ob, HIC "\n�����ڷɵ�����ԭ���׵�����������\n\n" NOR);
    	add("sb_ride", -1);
}
