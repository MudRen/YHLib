inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������ϴ�ּ�ʵ����ʯ������ϣ���ɫ�˵��������к�
�����֡���ʱ����ܻ����һЩ����װ����������ǿ�����
�죬����Ҳ�廨���ţ��������������㣬�ɲ��Ǻ��ǵġ�����
�����Ĵ�������ϴ�֡����Ϸ��Ǹ���Ρ��Ľ���Ⱥ���˽���
��ʮ�����֡�����ͨ������֡�
LONG);
        set("outdoors", "chengdu");
	set("exits", ([
	    	"northwest"  : __DIR__"westroad1",
	    	"southwest"  : __DIR__"wuhoucigate",
	    	"east"       : __DIR__"southroad2",
	]));
	set("objects", ([
	    	"/d/taishan/npc/jian-ke": 2,
	    	"/d/taishan/npc/dao-ke" : 1,
	]));
	setup();
	replace_program(ROOM);
}
