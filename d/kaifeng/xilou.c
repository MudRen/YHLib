inherit ROOM;

void create()
{
        set("short", "Ϸ¥");
        set("long", @LONG
һ��ľͷ�ִִ���ĸ�̨��̨�ĺ���ô��������������
�Ǻ�ͷ����Ϸ��װ����̨�ĵط��������ǹص����Ե�ʣ��ݵ�
�޷�����԰�����壬������ǧ�����ն�����ȹ��¡�
LONG);
        set("objects", ([
  		__DIR__"npc/qingyi" : 1,
  		__DIR__"npc/xiaosheng" : 1,
	]));
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"paifang",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
