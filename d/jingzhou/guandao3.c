inherit ROOM;

void create()
{
        set("short", "��ʯ��" );
        set("long", @LONG
�ӽ����ݣ�·�ɻ����������ʯ��·�����Խ������Կ���
һЩũ�ᣬũ����֣�������Ʈ���ųƾ���Ϊ����Ҫ�أ�����
Ϊ��һ������Ϊ�������������ȥ���ɼ����ݵĳ�¥�ˡ�
LONG);
        set("outdoors", "jingzhou");
        set("exits", ([
  		"east" : __DIR__"guandao2",
  		"west" : __DIR__"jzdongmen",
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

