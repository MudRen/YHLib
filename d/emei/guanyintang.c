inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ø߾��¸ڽ���Σ�£������ľ���������ľ��������
Ŀ���ġ���˵��ɽ�ڴˣ����ѳ�������ɽ�ڴˣ��������裬��
���������֡���ɽ�����ڴ˷���ϴ�ģ���ɽ���ɻ���Ϊ�Ĳ���
ƽ�������ﶫ�¿ɴ�����£�������Լ����ɵ����Ƹ�
LONG);
        set("exits", ([
                "eastdown"  : __DIR__"jietuopo",
                "westup"    : __DIR__"guiyunge",
        ]));
        set("outdoors", "emei");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
