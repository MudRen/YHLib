inherit ROOM;

void create()
{
        set("short", "���⸮����");
        set("long", @LONG
���ŵ�����վ�����ߣ����Ա�����ͷ����ͷ����ͷ����ա
���������ķ������˺�ëֱ����̨����߹ҡ���������������
����˴��ã�����Ҳ�����������ȥ���ǽֵ���
LONG
        );
        set("objects", ([
        	__DIR__"npc/baozheng" : 1,
	]));

        set("exits", ([
  		"east" : __DIR__"kaifeng",
	]));

        setup();
        replace_program(ROOM);
}
