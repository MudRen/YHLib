inherit ROOM;

void create()
{
        set("short", "�ٵ�" );
        set("long", @LONG
������һ����ٵ��ϣ����Բ�ʱ���˴�������߹�������
ͨ���ݣ�������һ��С·��
LONG);
        set("outdoors", "jingzhou");
        set("exits", ([
  		"east" : __DIR__"road7",
  		"west" : __DIR__"guandao2",
	]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

