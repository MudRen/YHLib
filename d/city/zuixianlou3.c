inherit ROOM;

void create()
{
        set("short", "����¥��¥");
        set("long", @LONG
��������¥��һ�����;��������ޱȣ��Ͷ�¥������ǡ��
���ȣ���ֱ���㲻�����š�����ԭ���ɾ����������Ҳ����̣
��һ����Ϳ����ˮ�ʵ����أ�������ƨ�ѵ����ݶ��ǡ����ϻ�
�в�����Ѫ����
LONG);
/*
        set("objects", ([
                __DIR__"npc/tao1" : 1,
                __DIR__"npc/tao2" : 1,
                __DIR__"npc/tao3" : 1,
                __DIR__"npc/tao4" : 1,
                __DIR__"npc/tao5" : 1,
                __DIR__"npc/tao6" : 1,
        ]));
*/
        set("exits", ([
                "down" : __DIR__"zuixianlou2",
        ]));
        setup();
	replace_program(ROOM);
}
