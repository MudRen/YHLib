//ROOM: /d/yanziwu/kuxiu2.c

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
                "west" : __DIR__"kuxiu",
        ]));
        set("for_family", "Ľ������");
        setup();
	replace_program(ROOM);
}
