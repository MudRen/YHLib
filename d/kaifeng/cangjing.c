inherit ROOM;

void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
�ؾ�¥��һ������С¥����¥�ж��Ƿ�Ҿ��䣬����ϡ��
�Ķ���̴ľ��ʢ���ˡ��ղ���¥�ϣ�����ר��ְ˾�������ۿ�
ȥ�������Ǹߵ͵���ܣ�
LONG);
        set("objects", ([
  		__DIR__"npc/zhifa" : 1,
	]));

        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"houyuan",
  		"up" : __DIR__"cangjing2",
  		"east" : __DIR__"xiaoyuan",
	]));

        setup();
        replace_program(ROOM);
}
