inherit ROOM;

void create()
{
        set("short", "��ʸ�");
        set("long", @LONG
��ʸ��ʮ�����������ϣ����÷�ľ�ṹ����ש���ɡ���
���¸���ͤ����Բ�·����������أ���һ�����ɹŰ����¥��
���ϣ�����Ԫ�����Ľ��������ڹ�������ͭ��һ��
LONG);
        set("no_clean_up", 0);
        set("exits", ([
		"east" : __DIR__"sanqing",
  		"up" : __DIR__"yuhuang2",
	]));

        setup();
        replace_program(ROOM);
}
