inherit ROOM;

void create()
{
        set("short", "�Ķ��Ͻ�");
        set("long", @LONG
�������ݳ��Ķ��Ͻ֣����Ľֵ����˲�������һ������
�쵽���ݵ��ϳ����ˡ�·����һ����վ��
LONG);
	set("outdoors", "zhongzhou");

        set("exits", ([
                "south" : __DIR__"nanmeng",
                "west" : __DIR__ "shuyuan",
                "north" : __DIR__"wendingnan3",
                "east" : __DIR__"yizhan",
	]));

        setup();
        replace_program(ROOM);
}

