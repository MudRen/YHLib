inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ݵ������ģ������ֵ������ﻮ����ʮ�֡�������
�ݾ����������ֵ��������ˡ�������̾���������ɫɫ������
���������ϱ�һ�����Ľֵ���һ�����Ǹո��޽��ò��ã�·
�������д�š��Ķ��֡������������ֵ�Ҫ�¾�һ�㣬һ��·
���ϵ����ѿ���̫�壬��ϡ���š�����·�������֡�
LONG);
	set("outdoors", "zhongzhou");
	set("exits", ([
  		"east" : __DIR__"yanlingdong",
  		"south" : __DIR__"wendingnan1",
  		"west" : __DIR__"yanling",
  		"north" : __DIR__"wendingbei1",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	setup();
}
