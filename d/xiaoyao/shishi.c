inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ʯͷ���ɵķ��䣬��Ϊ�þ�û����������ɢ����
Щ�����ŵ���ζ�������е������Կ�����˿�ͳ漣��
LONG);
	set("exits", ([
		"up" : __DIR__"midao",
	]));

	set("objects",([
		__DIR__"obj/putuan" : 1,
	]));

	set("objects",([
		CLASS_D("xiaoyao") + "/wuyazi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
