#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ˮ������");
	set("long", @LONG
��ǰ�ж�·�󣬵�·Ҳ��������������������ԼԼ�ƺ���
ˮ��֮���������㲻���볯���������ķ�����ȥ (zou)������
LONG);
	set("exits",([
	       "east" : __DIR__"zigai1",
	]));
	
	set("objects",([
	       "/clone/beast/yanjingshe" : 1,
	]));
	
	setup();

}


void init()
{
	object me = this_player();
	add_action("do_zou", "zou");
	add_action("do_use", "use");

	if (present("fire", me))
               	me->set_temp("marks/��", 1);

	else   	me->delete_temp("marks/��");
}	

int do_zou()
{
	object me = this_player();
	
	if (! me->query_temp("marks/��"))
		return notify_fail(HIW"\n����һƬ��ڣ����û�л��粽���С�\n\n"NOR);
	
	if (me->is_fighting() || me->is_busy())
		return notify_fail("\n��������æ���ء�\n\n");
	
	me->move(__DIR__"outzigai");
	
	return 1;
}


int do_use(string arg)
{
	object me = this_player();

	if (! arg || arg != "fire") return 0;
	
	if (! present("fire", me)) return 0;

	write(HIC "\n�㽫���۵�Ȼ�ˡ�\n\n" NOR);

	me->set_temp("marks/��", 1);

	return 1;

}
