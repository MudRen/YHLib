inherit ROOM;

void create()
{
	set("short", "�ƾɳ���");
	set("long", @LONG
������ΰ�ĳ�������Ŀȫ�ǣ����º�ս���Ѽ���������Ϊ
ƽ�ء�Ψһ�����һ����棬��������Ӣ�۵���ѪȾ�ɰ���ɫ��
������Ȼ��һƬ��ɱ��ȴ�м���С������ʯ�ķ�϶�м�������
����һ�������ĸо���
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
  		"west" : __DIR__"guandao4",
  		"east" : __DIR__"guandao2",
	]));

	setup();
	replace_program(ROOM);
}
