inherit ROOM;

void create()
{
        set("short", "��԰С·");
        set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ�·����Ӣ
�ͷף�һ���������֣�ʢ���ŷۺ���һ�������һƬ��������
�ߡ������Կ����۷䡸���ˡ����ڻ�����Ϸ���æ����ͣ����
����Գ���ߴզ��������������ɽ�Ļ���·��
LONG );
        set("outdoors", "wudang");
        set("exits", ([
                "south" : __DIR__"tyroad8",
        ]));
        set("objects", ([
                "/clone/quarry/hou" : 1
        ]));
        setup();
        replace_program(ROOM);
}
