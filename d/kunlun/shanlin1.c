inherit ROOM;

void create()
{
        set("short", "��ɼ��");
        set("long", @long
������һƬ�����޾��Ĵ��̵����֣����ܵ���ɼ������
��ɡ�����ص�����֦Ѿ��ֻ©�°߰ߵ��ϸ�����Ӱ��������
ʮ���ľ�������ȸҲ�ٷ�����ֻż��������Զ���ļ���������
long);
        set("exits",([
		"west" : __DIR__"shanlin2",
		"enter" : __DIR__"kuhanlou1",
		"southeast" : __DIR__"jiuqulang2",
		"northeast" : __DIR__"shanlin3",
	]));

	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
