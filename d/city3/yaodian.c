inherit ROOM;

void create()
{
	set("short", "������ҩ��");
	set("long", @LONG
������ҩ�����ܶ���ԭ�򲻵���ҩ�������ŵĸ�������һ
ֱ���ܺá�һ�߽����ҩ�꣬���ŵ���Ũ�Ҵ̱ǵ�ҩζ������
���ҩ�������������ܣ��Ϳ���ҩ���ﻹ��һЩ���������
���۹⿴�㡣���ǵ�����Ĺ����ҵģ���Ȼ���Ǻ��ǵġ�
LONG);
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"southeast" : __DIR__"westroad3",
	]));
	setup();
	replace_program(ROOM);
}
