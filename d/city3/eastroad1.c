inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ���ּ�ʵ����ʯ������ϡ��ϱ߿���ͨ�򶫳���
·����һ����ª�Ĳ�̯��һ��ϴ�÷����˵ľɷ���������ͷ��
�����������⣬һ�ų����Ϸ��ż�ֻ��Ŵִ��롣����ʢ����
�ɿڵĲ�ˮ��������ͨ������֣�������һ��������ﴫ����
��ȭ�����֡�
LONG );
        set("outdoors", "chengdu");
        set("resource/water", 1);
	set("exits", ([
	    	"northeast" : __DIR__"jiudian",
	    	"northwest" : __DIR__"northroad3",
	    	"south"     : __DIR__"eastroad2",
	]));
	set("objects", ([
	    	__DIR__"npc/xiaozei" : 1,
	]));
	setup();

        replace_program(ROOM);
}