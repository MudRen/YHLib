inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǻ컨���ܶ��ڴ�ű������صأ���������˱�����
ʮ�˰����������ȫ�������Ա߹�����ʮ����������Ŀ���
������սѥ���һλ��������Ŀ���񣬿��������
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"hh_guangchang",
	]));
        set("objects", ([
                "/clone/weapon/changjian" : 2,
                "/clone/weapon/gangdao" : 2,
                "/clone/weapon/zhubang" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
