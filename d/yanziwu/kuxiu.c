//ROOM: /d/yanziwu/kuxiu.c

inherit ROOM;

void create()
{
        set("short", "���޳�");
        set("long",@LONG
����ĳ�����Щ���䣬��Ȼ������ɨ�����ǳ�����Ȼ����
�����ٺۼ���ϣ������ͷ�ص�Ľ�ݼҵ������书����һ������
Ϊ�Ժ�����������������һ�������С�
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
                "west" : __DIR__"shijian",
		"east":  __DIR__"kuxiu2",
        ]));

        set("for_family", "Ľ������");
        setup();
	replace_program(ROOM);
}

