inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
���������ݽ�Զ��·�ϼ������������ˣ������ﲻ��Ҳ��
���������������ͨ�����ݸ������߲�Զ���Ǿ����ص������ǡ�
LONG);
        set("exits", ([
  		"west" : "/d/xiangyang/eastgate2",
  		"north" : __DIR__"nroad",
	]));

	set("outdoors", "zhongzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
