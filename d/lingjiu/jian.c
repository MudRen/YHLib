#include <ansi.h>; 
inherit ROOM;

void create()
{
  	set("short", "���ɽ�");
  	set("long", @LONG
ɽ������ͻȻ��ʧ��������ǰ��һ��ɽ����ɽ��֮������
���ƣ�������޷�������档һ������(tiesuo)�������У���
����һ��ʯ����
LONG);
  	set("outdoors", "lingjiu");
  	set("exits",([
      		"southdown" : __DIR__"yan",
  	]));
  	set("objects",([
                CLASS_D("lingjiu") + "/yupopo" : 1,
  	]));
  	set("item_desc",([
      		"tiesuo" : YEL "����������ͨ������Ľ����ţ���"
                           "Ҳ�������(zou)��ȥ��\n" NOR,
  	]));
  	setup();
}

void init()
{
	add_action("do_zou", "zou");
}

int do_zou(string arg)
{
	object me = this_player(), room;

	if (! arg || arg != "tiesuo")
		return notify_fail("��Ҫ��ʲô��\n");

	if (! (room = find_object(__DIR__"xianchou")))
		room = load_object(__DIR__"xianchou");

	if (! objectp(room))
		return notify_fail(HIW "���е���BUG��BUG��\n" NOR);

	message_vision(HIW "\nֻ��$N" HIW "����Ծ��������ƮȻ��"
                       "ȥ��\n" NOR, me);
        me->move(room);
	message_vision(HIW "$N" HIW "��������ƮȻ���£���������"
                       "翷������\n" NOR, me);
        return 1;
}

