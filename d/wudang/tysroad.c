inherit ROOM;

void create()
{
        set("short", "��԰С·");
        set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ�·����Ӣ
�ͷף�һ���������֣�ʢ���ŷۺ���һ�������һƬ��������
�ߡ������Կ����۷䡸���ˡ����ڻ�����Ϸ���æ����ͣ����
����Գ���ߴզ�����ϱ�������ɽ�Ļ���·��
LONG);
        set("outdoors", "wudang");
        set("exits", ([
                "north" : __DIR__"tyroad8",
        ]));
        setup();
        replace_program(ROOM);
}
