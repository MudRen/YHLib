inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
���⸮���������Ҫ��ͨҪ�����ֵ����ߵ�������������
���������̷���ߺ�ȣ�������С�����ּۻ��������ޱȡ���
���򱱲�Զ�͵�������۵Ĵ��š�
LONG
        );
        set("objects", ([
  		__DIR__"npc/lisi" : 1,
	]));
        set("outdoors", "kaifeng");
        set("exits", ([
  		"north" : __DIR__"wroad2",
  		"south" : __DIR__"wroad",
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
