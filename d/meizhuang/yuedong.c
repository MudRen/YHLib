inherit ROOM;

void create()
{
        set("short", "�¶���");
        set("long", @LONG
�㴩�����ȣ�����һ���¶���ǰ���¶����Ŷ���д�š����ġ���
�֣�����ɫ�������ɣ����²Ծ������ǳ���ͺ���̵��ֱ��ˡ�������
���ţ���һ�����ĵĻ��������������橣���������ʯ��������̦��
�Ե�ƽ���������С�
LONG
        );
        set("exits", ([
            "north" : __DIR__"xiaoyuan",
            "south" : __DIR__"xiaodao",
        ]));

        set("outdoors", "meizhuang");

        setup();
        replace_program(ROOM);
}
