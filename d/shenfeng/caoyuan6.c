inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
������һ���޼ʵĴ��ԭ����ɫ�Ĳݵ������þ������ʵ�
���졣��ԭ��������������Ⱥ����������Ʈ���Ķ����ơ�Զ
��������ɽ�ڽ����¿������紿��������Ϧ������ʱ�ֱ�ò�
����ƽ���Ҳ���û�뵽��������ı���֮�ؾ����������
�ĵط������ûԻͶ����أ����������Ի�
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
  		"westup" : __DIR__"caoyuan7",
  		"east" : __DIR__"xingxing2",
	]));
	setup();
	replace_program(ROOM);
}
