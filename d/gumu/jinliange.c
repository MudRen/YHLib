#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������λ�����ɽɽ���䣬������Ϊ��Ҫ������������
һ����ڴֵ�ӿȪ��Ȫˮ����͸�����������ˣ��ڵ�����Ϊ��
�����������ر����ˣ�ֻΪ��ȡ����ˮ���ݲ衣����ǰ��һ
��ʯ��(shibei)������һ������ά��ʫ�����Ͽ�ȥ��һ��ɽ·��
��������һ�����ѵ�ɽ·��
LONG
        );

        set("item_desc", ([
                "shibei"  : HIY
"

                �� �� �� ̫
                Ͷ Ұ �� ��
                �� �� �� ��  ��
                �� �� �� ��  ��
                �� �� �� ��  ɽ
                �� �� �� ��
                �� �� �� ��
                ˮ �� �� ɽ  ��
                �� �� �� ��  ά
                �� �� �� ��
                �� �� �� ��
                �� �� �� ��

" NOR, 
        ]));

        set("outdoors", "quanzhen");
        set("exits", ([
                "westup"     : __DIR__"shanlu10",
                "southdown"  : __DIR__"shanlu11",
        ]));

        setup();
        replace_program(ROOM);
}
