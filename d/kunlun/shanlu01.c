inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @long
�����Ѿ��������ɵĵط��ˣ�·�߻������أ������Ǻ���
���ڣ�����ȴ��Ȼ���������������������޵Ľ�����ǰ��ɽ��
���������ɵľ����ˣ�����������ʱ���ɽ�š�
long);
	set("exits",([
		"westdown" : __DIR__"shanmen",
		"southup" : __DIR__"shanlu02",
	]));

	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
