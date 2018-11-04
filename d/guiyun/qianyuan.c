#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
�����ǹ���ׯ��ǰԺ���൱�������ҿ�ǽ�����м����
����ƽ�������Ǽ��˵�ס������ǰ��������ľ��������紵��
��Ҷ�������¡�������һ�԰׵�(diao)��ë����ѩ��ԭ������
���һ���Ϊ������ӻص��ġ�
LONG );
        set("outdoors", "guiyun");
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("item_desc", ([
		"diao" : HIW "\n��һ�԰׵���չ�����ɡ�������һ���"
                         "�ĵ��ӣ�����(" HIY "ride" HIW ")��\n����"
                         "�ɵ��һ������ǳ�������\n\n" NOR,
	]));
	set("exits", ([
		"out"   : __DIR__"damen",
		"north" : __DIR__"dating",
	]));
	setup();
	"/clone/board/guiyun_b"->foo();
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
  	ob->move("/d/taohua/damen");
  	tell_object(ob, HIC "\n�����ڷɵ����һ������׵�����������\n\n" NOR);
    	add("sb_ride", -1);
}
